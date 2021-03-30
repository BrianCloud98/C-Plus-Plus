#ifndef CAR_H
#define CAR_H

using namespace std;
class Car
{
    public:
        Car();
        void stop();
        void setSpeed(int increment);
        int getSpeed();
    private:
        int speed = 0;

};

#endif
