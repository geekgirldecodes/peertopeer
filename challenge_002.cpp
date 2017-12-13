#include <iostream>
#include <stack>

using std::stack;

// File  : challenge_002.cpp
// Contains solution to peer to peer coding challenge 002
// Check if a given linked list is a palindrome

// Node of a linked list
typedef struct Node{
	int data;
	Node* next;
}Node;

Node* create_ll_node(int data){
	Node* n = new Node();
	if(NULL != n){
		n->data = data;
		n->next= NULL;
	}
	return n;
}


Node* build_test_list_1(){

	// sample linked list
	//  30->20->10->20->30

	Node* n1 =create_ll_node(30);
	Node* n2 =create_ll_node(20); 
	Node* n3 =create_ll_node(10); 
	Node* n4 =create_ll_node(10); 
	Node* n5 =create_ll_node(20);	
	Node* n6 =create_ll_node(30); 

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;

	return n1;
}

Node* build_test_list_2(){

	// sample linked list
	//  30->20->10->20->40
	Node* n1 =create_ll_node(30);
	Node* n2 =create_ll_node(20); 
	Node* n3 =create_ll_node(10); 
	Node* n4 =create_ll_node(20);	
	Node* n5 =create_ll_node(40); 

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;

	return n1;
}


// @Function isListPalindroma(Node* head)
// @Brief Checks if a given linked list is a palindrome
//        Needs O(n) extra space, n being length of linked list 
// @param1 pointer to head of linked list
// @return bool, True if palindrome else False

bool isListPalindrome(Node* head){
	if(NULL == head){
		return false;
	}

	// use a stack to hold the nodes of the linked list
	stack<int> st;
	Node* it = head; // iterator for the list
	int num_nodes = 0;

	while(NULL != it){
		st.push(it->data);
		it = it->next;
		num_nodes++;
	}

	/* compare the stack data with the linked list
	   we can stop comparision below at mid point of the list */
	int mid = num_nodes/2;
	it = head; // set iterator back to head

	while((num_nodes > mid) && (NULL != it)){
		if(it->data != st.top()){
			return false;
		}
		it = it->next;
		st.pop();
		num_nodes--;
	}

	return true;
}


int main(){

	//test 01
	Node* t1 = build_test_list_1();
	std::cout<<"Check if list is a palindrome "<<isListPalindrome(t1)<<std::endl;

    // test 02 
	Node* t2 = build_test_list_2();
	std::cout<<"Check if list is a palindrome "<<isListPalindrome(t2)<<std::endl;
}