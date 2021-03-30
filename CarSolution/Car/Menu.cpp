#include <iostream>
#include "Menu.h"
using namespace std;

Menu::Menu()
{
    Car car;
    printMenu();
}

void Menu::move()
{
    int amount;

    if (prompt == 2)
    {
        cout << "Set speed to how much (Mph)?" << endl;
        cin >> amount;
        if (amount > 0 || amount <= 100)
        {
            car.setSpeed(amount);
            cout << "You set your speed." << endl;
        }
        else
        {
            cout << "Please pick a number between 1 and 100." << endl;
        }

    }
    else if (prompt == 3)
    {
        if (car.getSpeed() == 0)
        {
            cout << "You are stopped." << endl;
        }
        else
        {
            cout << "Current speed: " << car.getSpeed() << " Mph" << endl;
        }
    }
    else if (prompt == 0)
    {
        car.stop();
        cout << "You have stopped." << endl;
    }
    else if (prompt == 7)
    {
        return;
    }

    printMenu();
}

void Menu::printMenu()
{
    cout << "Type 2 to set speed, 3 to check speed, and 0 to put on the brakes. Press 7 to Exit.";
    cin >> prompt;
    move();
}