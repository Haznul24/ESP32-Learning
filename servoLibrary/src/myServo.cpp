#include "myServo.h"

myServo::myServo(int pin, int channel, int minAngle, int maxAngle) {
    _pin = pin;
    _channel = channel;
    _minAngle = minAngle;
    _maxAngle = maxAngle;
    _lastTime = 0;
    _interval = 20;

    ledcSetup(_channel, 50, 16);
    ledcAttachPin(_pin, _channel);
}

int myServo::angleToPulse(int angle) {
    return map(angle, 0, 180, 1638, 8192);
}

void myServo::move(int targetAngle) {
    targetAngle = constrain(targetAngle, _minAngle, _maxAngle);
    unsigned long currentTime = millis();

    _currentAngle = targetAngle;

    if (currentTime - _lastTime >= _interval) {
        _lastTime = currentTime;

        ledcWrite(_channel, angleToPulse(targetAngle));

    }
}

void myServo::moveTo(int angle, int speed) {
    _targetAngle = constrain(angle, _minAngle, _maxAngle);
    unsigned long currentTime = millis();

    if (currentTime - _lastTime >= _interval) {
        float step = speed * (_interval / 1000.0);

        if (_currentAngle < _targetAngle ) {
            _currentAngle += step;
            if (_currentAngle > _targetAngle) _currentAngle = _targetAngle;
        }
        else if (_currentAngle > _targetAngle ) {
            _currentAngle -= step;
            if (_currentAngle < _targetAngle) _currentAngle = _targetAngle;
        }

        ledcWrite(_channel, angleToPulse(_currentAngle));
        _lastTime = currentTime;
    }
}

int myServo::getAngle() {
    return Serial.println(_currentAngle);
}