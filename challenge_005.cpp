#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;

// File  : challenge_005.cpp
// Contains solution to peer to peer coding challenge 005
// Given an input array of numbers and a number "k", 
// find an optimal algorithm to return all combinations of 
// numbers in the input array which have a difference of "k"

// data structure to store number combinations
typedef struct numbers{
	int num1;
	int num2;
}numbers;


// @Function fnd_numbers_with_diff_k(int[] input , int n, int k , vector<numbers>& output)
// @Brief updates output array with number combinations whose diff is "k"
// @param1 input array
// @param2 "k" 
// @return all unique combinations of numbers in input array whose difference is 'k'
// Takes : O(nlogn)+O(n)

void find_numbers_with_diff_k(int input[], int n , int k , vector<numbers>& output){

	// 1. sort the array (O(nlogn))
	std::sort(input, input+n);	

	// 2. loop through array usign two pointers, 
	// finding unique number combinations in ~O(n)
	int left = 0;
	int right = 0;
	int count = 0;
	int diff = 0 ;

	while(right < n){
		
		if((diff = input[right] - input[left]) == k){
			//save these numbers onto output vector
			numbers n;
			n.num1 = input[left];
			n.num2 = input[right];
			output.push_back(n);

			//increment pointers to keep searching
			count++;
			right++;
			left++;
		}
		else if(diff > k){
			left++;
		}
		else{
			right++;
		}
	}
}


void test_001(){

	int in[] = {4,2,3,5,1};
	vector<numbers> output;
	find_numbers_with_diff_k(in, 5,2, output);
	std::cout<<"output is "<<output.size()<<std::endl;
	for(int i =0; i <output.size(); i++){
		std::cout<<output.at(i).num1<<" "<<output.at(i).num2<<std::endl;
	}

}

void test_002(){

	int in[] = {4,-2,3,-5,1};
	vector<numbers> output;
	find_numbers_with_diff_k(in, 5,2, output);
	std::cout<<"output is "<<output.size()<<std::endl;
	for(int i =0; i <output.size(); i++){
		std::cout<<output.at(i).num1<<" "<<output.at(i).num2<<std::endl;
	}

}

void test_003(){

	int in[] = {4,2,3,5,1,2};
	vector<numbers> output;
	find_numbers_with_diff_k(in, 6,2, output);
	std::cout<<"output is "<<output.size()<<std::endl;
	for(int i =0; i <output.size(); i++){
		std::cout<<output.at(i).num1<<" "<<output.at(i).num2<<std::endl;
	}

}

int main(){
	//only positive integers
	test_001();

	// signed integers
	test_002();

	//with duplicates 
	//( test if we return only unique numbers)
	test_003();
}