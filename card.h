
#ifndef _CARD_H
#define _CARD_H


#include <iostream>
#include <string>
using namespace std;

class Card
{
  public:

    enum Suit {spades, hearts, diamonds, clubs};
    
    Card();                     // default: ace of spades

    Card(int, Suit);

    string toString()   const;  // return string version: Ac 4h Js
    int   getRank()     const;  // return rank, 1..13
    Suit  getSuit()     const;  // return suit
    
    
    bool operator == (const Card &rhs) const;
    
  private:

    int rank;
    Suit suit;

    string suitString()  const;  // return "s", "h",...
    string rankString()  const;  // return "A", "2", ..."Q"*/
    
};

#endif
