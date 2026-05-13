#ifndef myServo_h
#define myServo_h

#include <Arduino.h>

class myServo {
    private:
        int _pin;
        int _channel;
        int _targetAngle;
        int _minAngle;
        int _maxAngle;
        float _currentAngle;

        unsigned long _lastTime;
        int _interval;

        int angleToPulse(int angle);

    public:
        myServo(int pin, int channel, int minAngle = 0, int maxAngle = 180);
        void move(int targelAngle);
        void moveTo(int angle, int speed);
        int getAngle();
};

#endif