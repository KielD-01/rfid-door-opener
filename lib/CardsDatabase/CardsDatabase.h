#include <Arduino.h>
#include <RFID.h>

struct Card
{
    String *readableSerialNo;
};

struct CardsDatabaseStructure
{
    String *cards[] = {};
    int amount = 0;
};

class CardsDatabase
{
public:
    const int DB_EEPROM_KEY = 10;

    Card lastReadCard;

    // Constructor variations
    CardsDatabase();

    bool authorizeCard(String *card); // Check, if card exists
    bool addCard(String card);        // Adds a card to database
    bool clearDatabase();             // Clears a cards database
    String readCardSerial(RFID rfid); // Returns a string of a card identifier

    CardsDatabaseStructure getCards(); // Returns a struct of CardsDatabaseStructure
    Card getLastReadCard();

private:
    CardsDatabaseStructure db;
    void updateDatabase(); // Updates database
};