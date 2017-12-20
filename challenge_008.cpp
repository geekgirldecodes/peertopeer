#include <iostream>
#include <cassert>

// File  : challenge_008.cpp
// Contains solution to peer to peer coding challenge 008
// check if a given path sum exists in a binary search tree
// bst can contain negative integers 

// structure to hold node of BST
typedef struct Node{
	int data;
	Node* left;
    Node* right;
}Node;


//creates a new node with data provided 
Node* create_node(int data){
	Node* n1 = new Node();
	if(n1 != NULL){
		n1->data = data;
		n1->right = n1->left= NULL;
	}
	return n1;
}

// test stub
// creates a sample binary tree and returns head node
Node* build_test_bst(){

	// sample test binary search tree 
	//     30
	//  /     \
	// -15     40
	// / \     / \
	//-25 -10 35 45

	Node* n1 =create_node(30);

	Node* n2 =create_node(-15); // left
	Node* n4 =create_node(-25); 
	Node* n5 =create_node(-10);	

	Node* n3 =create_node(40); // right
	Node* n6 =create_node(35); 
	Node* n7 =create_node(45);
	

	n1->left = n2; 
	n1->right = n3; 

	n1->left->left = n4;
	n1->left->right = n5;

	n1->right->left = n6;
	n1->right->right = n7;

	return n1;
}

// make a test binary tree

bool has_path_sum(Node* node, int sum){

	if(NULL == node){
		return (sum==0);
	}

	else{
		int remaining_sum = sum-node->data;
		return (has_path_sum(node->left, remaining_sum)|| has_path_sum(node->right,remaining_sum));
	}
}


//check for valid -ve sum
void test_001(){

	Node* node = build_test_bst();
	assert(1==has_path_sum(node, 5));	
}

//check for invalid sum
void test_002(){
	Node* node = build_test_bst();
	assert(0==has_path_sum(node, 10));	
}

//check for positive sum
void test_003(){
	Node* node = build_test_bst();
	assert(1==has_path_sum(node, 115));	
}

int main(){
	test_001();
	test_002();
	test_003();
}
