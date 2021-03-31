#include <iostream> 
#include <fstream>
#include <string>
using namespace std;

void findFreq(string line, int chars[])
{
	int count = 0;
	int i = 0;

	while (line[count] != '\0')
	{
		if (line[count] >= 'a' && line[count] <= 'z')
		{
			i = line[count] - 'a';

			++chars[i];
		}

		++count;
	}

}

void printfreq(int chars[])
{
	cout << endl;
	cout << "The frequency of characters is:" << endl;
	cout << "----------------" << endl;

	for (int i = 0; i < 26; i++)
	{
		cout << char(i + 'a') << ": " << chars[i] << endl;
	}
}

void readfile(int chars[])
{
	string inputFileName = "file.txt";
	ifstream readf(inputFileName);

	if (readf.is_open())
	{
		string line;

		while (getline(readf, line))
		{
			cout << line << endl;
			findFreq(line, chars);
		}
		readf.close();
	}
}

int main()
{
	int chars[26] = { 0 };

	readfile(chars);
	printfreq(chars);

	return 0;
}