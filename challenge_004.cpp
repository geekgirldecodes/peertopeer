#include <iostream>
#include <cstdint>

// File  : challenge_004.cpp
// Contains solution to peer to peer coding challenge 004
// Given an input number find the nearest power of 2.

// @Function find_nearest_pow_of_two(int num)
// @Brief not so optimized but straightforward way to do this
// @param1 input number
// @return nearest power of two

int find_nearest_power_of_two(int num){

	if(0 == num){
		return num;
	}

	int pow_of_two = 0;
	 
	while(num > 0){
		num=num/2;
		pow_of_two++;
	}

	return pow_of_two;
}

int main(){
	//test
	find_nearest_power_of_two(64);
}