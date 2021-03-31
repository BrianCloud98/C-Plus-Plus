#pragma once
#ifndef RANDOM_NUMBERS_H
#define RANDOM_NUMBERS_H
using namespace std;

class RandomNumbers
{
	public: 
		RandomNumbers();
		void printRandom(int numbers[]);
		int numbers[50];
		//Number of random numbers
		const int  NUM_ITEMS = 50;
};

#endif
