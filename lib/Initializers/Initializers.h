#include <Arduino.h>
#include <Helpers.h>

class Initializers
{
public:
    // Pins defining
    const int BUZZER_PIN = 8;
    const int LED_G_PIN = 7;
    const int LED_R_PIN = 6;

    // Buzzer Frequencies
    const int BUZZER_SUCCESS_TONE = 100;
    const int BUZZER_FAILURE_TONE = 25;

    // Buzzer duration of the tone
    const int BUZZER_TONE_DURATION = .5;

    // Signal Timeouts (in seconds)
    const float LED_TIMEOUT = .5;
    const float BUZZER_TIMEOUT = .2;

    // Custom defined
    const int TEST_BUZZER_FREQUENCY = 500;

    Initializers();

    void initLEDLights();
    void initLEDLights(unsigned long &timeToTurnOfLeds, unsigned long &currentTime, bool secondInit = false);
    void initBuzzer();
};