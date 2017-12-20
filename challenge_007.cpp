#include <iostream>

// File  : challenge_007.cpp
// Contains solution to peer to peer coding challenge 007
// Reverse a linked list starting at "kth" node.

// Singly linked list node
typedef struct Node{
	int data;
	Node* next;
}Node;

//helper to create a test singly linked list
Node* create_ll(){

	Node* n1 = new Node();
	n1->data = 1;
	Node* n2 = new Node();
	n2->data = 2;
	Node* n3 = new Node();
	n3->data = 3;
	Node* n4 = new Node();
	n4->data = 4;
	Node* n5 = new Node();
	n5->data = 5;
	Node* n6 = new Node();
	n6->data = 6;
	Node* n7 = new Node();
	n7->data = 7;
	Node* n8 = new Node();
	n8->data = 8;

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = n7;
	n7->next = n8;
	n8->next = NULL;

	return n1;

}

// @Brief Helper function to reverse linked list and update prior nto kth node.
// @param1  pointer to pointer to the starting point for reversal (kth node)
// @param2  pointer to pointer to the prior to kth node , to be update once reversal is complete

void reverse(Node** head, Node** p){

	if(NULL == head){
		return ;
	}

	Node* pr = *p ;

	// reverse starting at kth node
	Node* curr = *head;
	Node* prev = NULL;
	Node* backup ;
	
	while(NULL != curr){
		backup = curr->next;
		curr->next = prev;
		prev = curr;
		curr = backup;
	}

	// update the next pointer of previous to kth node.
	pr->next = prev;
}


// @Function reverse_ll_from_k(Node* head)
// @Brief Reverses a linked list starting at kth node
// @param1 pointer to pointer to head of the input linked list
// @param2 k, index where the reversal should start
// @return updates the linked list passed with required reversal

void reverse_ll_from_k(Node** head, int k){

	if(NULL == *head){
		return ;
	}

	Node* it = *head;
	int count = 0;
	Node* p = it; // to iterate the list

	// find the node we have to start reversal at and the node prior to that
	// we need to update the prior node's next to point to updated reversed list

	while((NULL != it->next)&&(count != k-1)){
		p = it;
		it = it->next;
		count++;
	}

	//we have reached the end of the list and k exceeds count
	if((it->next == NULL)&&(k > count)){
		std::cout<<"Error , k greater than nodes in the linked list "<<std::endl;
		return;
	}

	// call reverse helper method to do the reversal and update prior node as well.
	reverse(&it, &p);

}


// Test stubs 

void test_001(){
	Node* head = create_ll();
	reverse_ll_from_k(&head,3);
	
	while(NULL != head){
		std::cout<<"data "<<head->data<<std::endl;
		head = head->next;
	}
	
}


void test_002(){
	Node* head = NULL;
	reverse_ll_from_k(&head,2);
}

void test_003(){
	Node* head = create_ll();
	reverse_ll_from_k(&head,8);
}


// call test stubs 
int main(){

	// Test correct input 
	test_001();

	//Test null input
	test_002();

	//test input with k > num nodes in linked list (error)
	test_003();

	return 0;
}