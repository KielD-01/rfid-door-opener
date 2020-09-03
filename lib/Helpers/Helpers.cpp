#include <Arduino.h>

void refreshCurrentTime(unsigned long &currentTime)
{
    currentTime = millis();
}

unsigned int getCurrentTime()
{
    return millis();
}

bool hasPassed(unsigned int targetTime)
{
    return targetTime <= getCurrentTime();
}

unsigned long convertTime(float time)
{
    return time * 1000;
}

void log(String message)
{
    if (Serial)
        Serial.println(message);
}

void turnLED(int pin, int duration)
{
    digitalWrite(pin, HIGH);
}