#include <iostream>
#include "Start.h"
#include "Menu.h"
using namespace std;

Start::Start()
{
    int start;

    cout << "Type 1 to start driving or any other key to exit." << endl;
    cin >> start;

    if (start == 1)
    {
        Menu();
    }
}