#pragma once
#include "Card.h"

class CardList :
    public Card
{
public:
    Card card[MAX_CARD];
    int CardNumber;
    CardList();
    ~CardList();
};

