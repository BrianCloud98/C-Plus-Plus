#include <iostream>
#include<random>
#include<ctime>
#include "RandomNumbers.h"

using namespace std;

RandomNumbers::RandomNumbers()
{
	//Seed the random using time()
	srand(time(NULL));

	//Add random numbers to an array
	for (int i = 0; i < NUM_ITEMS; i++)
	{
		numbers[i] = rand() % 100 + 1;
	}
}

void RandomNumbers::printRandom(int numbers[])
{
	//Prints the numbers array to console
	for (int i = 0; i < NUM_ITEMS; i++)
	{
		cout << numbers[i] << "  ";
	}
	cout << endl;

}