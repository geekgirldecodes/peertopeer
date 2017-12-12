#include <iostream>
#include <limits.h>
#include <vector>
#include <cassert>

using std::vector;

// File  : daily_challenges.cpp
// Contains solutions to peer to peer coding challenges.

// Node of a Binary Search Tree
typedef struct Node{
	int data;
	Node* left;
	Node* right;
}Node;

// Helper stub for testing
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
	//    30
	//  /   \
	// 20    40
	// / \   / \
	//15 25 35 45

	Node* n1 =create_node(30);

	Node* n2 =create_node(20); // left
	Node* n4 =create_node(15); 
	Node* n5 =create_node(25);	

	Node* n3 =create_node(40); // right
	Node* n6 =create_node(35); 
	Node* n7 =create_node(45);
	

	n1->left = n2; //20
	n1->right = n3; //30

	n1->left->left = n4;
	n1->left->right = n5;

	n1->right->left = n6;
	n1->right->right = n7;

	return n1;
}

// Helper stub to print output
void preorder_t(Node* root){
	
	if(NULL == root){
		return;
	}

	std::cout<< root->data<<" ";
	preorder_t(root->left);
	preorder_t(root->right);
}

// @Function create_in_order_aux_array(Node* head, vector<int>& output)
// @Brief Helper function to create an array to hold in-order 
//        traversal auxiliary output
// #refer challenge #1 , convertBstToHeap()
// @param1 pointer to binary search tree 
// @param2 auxiliary vector to hold in-order traversal output
// @return None, update aux array passed

void create_in_order_aux_array(Node* node, vector<int>& output){

	if(NULL == node){
		return;
	}

	create_in_order_aux_array(node->left, output);
	//add to aux array
	output.push_back(node->data);
	create_in_order_aux_array(node->right, output);
}

// @Function aux_arr_to_bst_min_heap(Node* head, vector<int>& aux_arr, int* i)
// @Brief Helper function to update the BST to heap
// #refer challenge #1 , convertBstToHeap()
// @param1 pointer to binary search tree 
// @return None, update BST passed

void aux_arr_to_bst_min_heap(Node* node, vector<int>& aux_arr, int* i){

	if(NULL == node){
		return;
	}

	// similar to preorder traversal of BST
	// For min heap go forwards on the sorted aux array
	node->data = aux_arr[++*i];
	aux_arr_to_bst_min_heap(node->left, aux_arr, i);
	aux_arr_to_bst_min_heap(node->right, aux_arr, i);

}

// @Function aux_arr_to_bst_max_heap(Node* head, vector<int>& aux_arr, int* i)
// @Brief Helper function to update the BST to heap
// #refer challenge #1 , convertBstToHeap()
// @param1 pointer to binary search tree 
// @return None, update BST passed

void aux_arr_to_bst_max_heap(Node* node, vector<int>& aux_arr, int* i){

	if(NULL == node){
		return;
	}

	// similar to pre order traversal of BST
	// For max heap go backwards on the sorted aux array
	node->data = aux_arr[--*i];
	aux_arr_to_bst_max_heap(node->left, aux_arr, i);
	aux_arr_to_bst_max_heap(node->right, aux_arr, i);

}

// Challenge #1
// @Function convertBstToMinHeap()
// @brief Method to convert a given binary seach tree to a Min heap
//        Takes O(n) extra space
// @param1 pointer to root node of bst
// @return None, updates BST passed to a Min heap

void convertBstToMinHeap(Node* root){

	if(NULL == root){
		return;
	}

	vector<int> aux_arr ;
	//step 1. create aux array , sorted elements
	create_in_order_aux_array(root, aux_arr);
	//step 2. update the nodes of the BST in preorder fashion from aux arr
	// for a min heap start at first node of the aux_arr
	int i = -1;
	aux_arr_to_bst_min_heap(root, aux_arr, &i);
	std::cout<<"\n";

}

// @Function convertBstToMaxHeap()
// @brief Method to convert a given binary seach tree to a Max heap
//        Takes O(n) extra space
// @param1 pointer to root node of BST
// @return None, updates BST passed to a Max heap

void convertBstToMaxHeap(Node* root){

	if(NULL == root){
		return;
	}
	
	vector<int> aux_arr ;
	//step 1. create aux array , sorted elements
	create_in_order_aux_array(root, aux_arr);
	int i = aux_arr.size();

	//step 2. update the nodes of the BST in preorder fashion from aux arr
	// for a max heap start at last node of the aux_arr(from aux_arr.size() index))
	aux_arr_to_bst_max_heap(root, aux_arr, &i);
	std::cout<<"\n";

}

// Tester methods
void test_challenge_1_a(Node* head){
	// Min heap creation from given BST
	std::cout<<"Input BST :"<<" ";
	preorder_t(head);
	convertBstToMinHeap(head);
	std::cout<<"Output Min heap :"<<" ";
	preorder_t(head);
}

void test_challenge_1_b(Node* head){
	// MAx heap creation from given BST
	std::cout<<"Input BST :"<<" ";
	preorder_t(head);
	convertBstToMaxHeap(head);
	std::cout<<"Output Max heap :"<<" ";
	preorder_t(head);
}

void test_operations(){
	// build test trees
	Node* t1 = build_test_bst();
	Node* t2 = build_test_bst();

	test_challenge_1_a(t1);
	std::cout<<"\n";
	test_challenge_1_b(t2);
	std::cout<<"\n";

}

int main(){
	test_operations();
}