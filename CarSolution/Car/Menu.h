#pragma once
#ifndef MENU_H
#define MENU_H
#include "Car.h"

using namespace std;
class Menu
{
	public:
		Menu();
		void move();
		void printMenu();
	private:
		int prompt;
		Car car;
};

#endif