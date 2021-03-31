#include <iostream>
#include "Sort.h"
#include "RandomNumbers.h"

using namespace std;

Sort::Sort()
{
	
}

Sort::Sort(int numbers[])
{
	int i, j, temp;

	for (i = 49; i >= 0; i--)
	{
		for (j = 1; j <= i; j++)
		{
			if (numbers[j - 1] > numbers[j])
			{
				temp = numbers[j - 1];
				numbers[j - 1] = numbers[j];
				numbers[j] = temp;
			}
		}
	}
}