

#ifndef _DECK_H
#define _DECK_H

#include "card.h"

class Deck
{
  static const int SIZE = 52;
  
  public:
    
    Deck();            // pristine, shuffled deck (cards in random order)

    Card dealCard();   // get a card, after 52 are dealt, fail

    int size() const;  // # cards left in the deck

  private:

    Card cards[SIZE];  // ARRAY
    int index;         // current card to deal
};

#endif
