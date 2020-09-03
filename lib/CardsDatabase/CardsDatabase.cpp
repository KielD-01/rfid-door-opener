#include <CardsDatabase.h>
#include <EEPROM.h>

CardsDatabase::CardsDatabase()
{
    if (EEPROM.read(CardsDatabase::DB_EEPROM_KEY) == 255)
    {
        this->db = CardsDatabaseStructure{};
        return;
    }

    EEPROM.get(CardsDatabase::DB_EEPROM_KEY, this->db);
}

void CardsDatabase::updateDatabase()
{
    EEPROM.put(CardsDatabase::DB_EEPROM_KEY, this->db);
}

bool CardsDatabase::clearDatabase()
{
    String cards[] = {};

    *this->db.cards = cards;
    this->db.amount = 0;
}

bool CardsDatabase::addCard(String card)
{
    this->db.amount += 1;
}

bool CardsDatabase::authorizeCard(String *card)
{
    for (int cardIndex = 0; cardIndex < this->db.amount; cardIndex++)
    {
        if (this->db.cards[cardIndex] == card)
        {
            return true;
        }
    }

    return false;
}

String CardsDatabase::readCardSerial(RFID rfid)
{
    rfid.readCardSerial();

    String cardNo = "";
    for (int i = 0; i < 5; i++)
    {
        cardNo.concat(rfid.serNum[i]);
    }

    this->lastReadCard = Card{cardNo};

    return cardNo;
}

Card CardsDatabase::getLastReadCard()
{
    return this->lastReadCard;
}

CardsDatabaseStructure
CardsDatabase::getCards()
{
    this->db = this->getCards();
    return this->db;
}