#include <Arduino.h>
#include <Initializers.h>
#include <Helpers.h>

void Initializers::initLEDLights()
{
    log("Setting Pin mode for LED's : OUTPUT");

    pinMode(LED_G_PIN, OUTPUT);
    pinMode(LED_R_PIN, OUTPUT);

    digitalWrite(LED_G_PIN, HIGH);
    digitalWrite(LED_R_PIN, HIGH);
}

void Initializers::initLEDLights(unsigned long &timeToTurnOfLeds, unsigned long &currentTime, bool secondInit = false)
{
    if (secondInit)
    {
        timeToTurnOfLeds = timeToTurnOfLeds == 0 ? getCurrentTime() + convertTime(LED_TIMEOUT) : timeToTurnOfLeds;

        if (getCurrentTime() >= timeToTurnOfLeds)
        {
            digitalWrite(LED_G_PIN, LOW);
            digitalWrite(LED_R_PIN, LOW);

            refreshCurrentTime(currentTime);
        }
    }

    return;
}

void Initializers::initBuzzer()
{
    log("Setting Pin mode for Buzzer : OUTPUT");

    pinMode(BUZZER_PIN, OUTPUT);
    tone(BUZZER_PIN, TEST_BUZZER_FREQUENCY, convertTime(BUZZER_TIMEOUT));
}