// Including needed Libraries
#include <Arduino.h>
#include <RFID.h>
#include <Helpers.h>
#include <CardsDatabase.h>
#include <Initializers.h>

unsigned long currentTime;
unsigned long timeToTurnOfLeds = 0;

int buzzerToneDuration = convertTime(init.BUZZER_TONE_DURATION);

// Hardware
RFID rfid;
CardsDatabase cdb;
Initializers init;

void setup()
{
  Serial.begin(9600);
  log("Serial Monitor is enabled");

  init.initLEDLights();
  init.initBuzzer();
}

void loop()
{
  init.initLEDLights(timeToTurnOfLeds, currentTime, true);

  if (rfid.isCard())
  {
    cdb.readCardSerial(rfid);
    cdb.authorizeCard(cdb.getLastReadCard().readableSerialNo) ? 
    tone(init.BUZZER_PIN, init.BUZZER_SUCCESS_TONE, buzzerToneDuration) :
     tone(init.BUZZER_PIN, init.BUZZER_FAILURE_TONE, buzzerToneDuration);
  }

  refreshCurrentTime(currentTime);
}