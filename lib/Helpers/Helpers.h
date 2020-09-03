#include <Arduino.h>

void refreshCurrentTime(unsigned long &currentTime);
void log(String message);

unsigned int getCurrentTime();
unsigned long convertTime(float time);

bool hasPassed(unsigned int targetTime);

void turnLED(int pin, int duration);