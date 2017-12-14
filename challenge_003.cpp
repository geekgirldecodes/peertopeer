#include <iostream>
#include <stack>

using std::stack;

// File  : challenge_003.cpp
// Contains solution to peer to peer coding challenge 003
// Find the next smallest number for every number in an input array
// Example : Input [2,3,5,6,4] , Output expected [-1,-1,4,4,-1]

// @Function get_next_smaller_elements( )
// @Brief Updates the output array passed with next smaller elements per element of input array
//        Needs O(n) time, n being length of the array 

void get_next_smaller_elements(int input[], int output[], int len){

	// use a stack to hold the indicies
	stack<int> st;

	/* Idea :
		 * Traverse the array and keep tracking if any smaller element than at the current index
		 * until we find a smaller element keep pushing the index of all elements traversed on to the stack
		 * when you hit smaller element, it is essentially the value that is to be filled onto 
		 * output array at all corresponding indexes that were pushed on the stack */ 

	for(int i=0; i<len;i++){

		while((st.size()>0) &&(input[i]<input[st.top()])){
			output[st.top()]=input[i];
			st.pop();
		}

		// push this to stack
		st.push(i);
	}
}

void test(){
	int input[5] = {2,3,5,6,4};
	int output[5] = {-1,-1,-1,-1,-1};
	get_next_smaller_elements(input, output, 5);

	for(int j=0;j<5;j++){
		std::cout<<output[j]<<std::endl;
	}
}

int main(){
	test();
} 

