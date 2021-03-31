#include <iostream>
#include <random>
#include <ctime>
#include "RandomNumbers.h"
#include "Sort.h"

using namespace std;

// This program creates 50 random numbers between 1-100 then uses bubblesort to sort them into order.
int main()
{
	RandomNumbers RandNum;
	int prompt;

	cout << "The random numbers are:" << endl;
	RandNum.printRandom(RandNum.numbers);

	cout << "Press 1 to sort." << endl;
	cin >> prompt;
	if (prompt == 1)
	{
		Sort(RandNum.numbers);
	}

	cout << "The sorted numbers are:" << endl;
	RandNum.printRandom(RandNum.numbers);
	return 0;
}



