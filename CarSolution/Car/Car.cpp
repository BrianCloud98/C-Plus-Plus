#include "Car.h"

using namespace std;

Car::Car()
{

}

void Car::stop()
{
    speed = 0;
}

void Car::setSpeed(int increment)
{
    speed = increment;
}

int Car::getSpeed()
{
    return speed;
}
