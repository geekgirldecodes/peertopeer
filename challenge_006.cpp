#include <iostream>
#include <algorithm>

// File  : challenge_006.cpp
// Contains solution to peer to peer coding challenge 006
// Given an input array of numbers and a number "target", 
// find if pair of numbers exist with difference between them = target.


bool contains_pair_with_diff(int input[], int size, int target ){

	//1. sort the array (O(logn))
	std::sort(input, input+size);

	//2. find if there is a pair using two pointers, O(n)

	int left = 0;
	int right = 0;
	int diff = 0 ;
	
	while(right < size){
		if((diff = input[right]-input[left]) == target){
			//found  a pair
			return true;
		}
		else if(diff > target){
			left++;
		}
		//if diff < target
		else{
			right++;
		}
	}

	// we did not a find a pair
	return false;

}

//test with a pair
void test_001(){
	int in[] = {4,2,3,5,1};
	std::cout<<"Pair found "<<contains_pair_with_diff(in, 5 , 2)<<std::endl;	
}

//test without a pair
void test_002(){
	int in[] = {4,2,3,5,1};
	std::cout<<"Pair found "<<contains_pair_with_diff(in, 5 , 6)<<std::endl;	
}

int main(){
	test_001();
	test_002();
}
