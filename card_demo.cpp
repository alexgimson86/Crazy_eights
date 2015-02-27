
#include <iostream>    
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;


//***********************************************************
// dealHand: deals a specified number of cards from the deck
//           into a player's hand.
// d: the Deck of Dards
// p: the Player
// numCards: the number of cards to deal
//***********************************************************

void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}
bool checkWin(int handSize)
{
	if (handSize == 0)
		return true;
	else return false;
}



int main( )
{
    int numCards =5; // size of a hand
	Card discard;
	Player p1("Joe");    // player 1
    Player p2("Jane");   // player 2
	bool win = false;
	bool hasCard;

    
    // create a deck of cards (shuffled).
    Deck d;

    // deal out cards to each player
    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);
	discard = d.dealCard();

    //show hands of each player
    cout << p1.getName() <<" has : " << p1.showHand() << endl;
	cout << p2.getName() << " has : " << p2.showHand() << endl;
	cout << discard.toString() << " is the discard. " << endl;

	//if decksize gets to zero its a draw 
	// if win equals true exit loop too
	while (d.size() > 0 && win == false)
	{
		hasCard = false;


		//in this while, if player one has card with suit or 
		//rank he plays it otherwise he draws another card

		while (!hasCard && d.size() > 0 && win == false)
		{

			if (p1.hasCardWithRank(discard.getRank(), discard))
			{
				p1.removeCardFromHand(discard);
				cout << p1.getName() << " plays a " << discard.toString() << endl;
				hasCard = true;
			}
			else if (p1.hasCardWithSuit(discard.getSuit(), discard))
			{
				p1.removeCardFromHand(discard);
				cout << p1.getName() << " plays a " << discard.toString() << endl;
				hasCard = true;
			}
			else
			{
				if (d.size() > 0)
				{
					Card temp = d.dealCard();
					p1.addCard(temp);
					cout << p1.getName() << " draws a " << temp.toString() << endl;
				}
			}
		}
		hasCard = false;

		//check if player one won in that above while loop
		//if so we skip this next loop and end game
		if (checkWin(p1.getHandSize()))
			win = true;
		
		//same as above while loop except for with player 2
		while (!hasCard && d.size() > 0 && win == false)
		{

			if (p2.hasCardWithRank(discard.getRank(), discard))
			{
				p2.removeCardFromHand(discard);
				cout << p2.getName() << " plays a " << discard.toString() << endl;
				hasCard = true;
			}
			else if (p2.hasCardWithSuit(discard.getSuit(), discard))
			{
				p2.removeCardFromHand(discard);
				cout << p2.getName() << " plays a " << discard.toString() << endl;
				hasCard = true;
			}
			else
			{
				if (d.size() > 0)
				{
					Card temp = d.dealCard();
					p2.addCard(temp);
					cout << p2.getName() << " draws a " << temp.toString() << endl;
				}
			}
		}
		hasCard = false;

		if (checkWin(p2.getHandSize()))
			win = true;

	}

	//print out who won
	cout << "game over \n";
	if (d.size() == 0)
		cout << "its a draw! " << endl;
	else if (checkWin(p1.getHandSize()))
		cout << p1.getName() << " wins!" << endl;
	else if (checkWin(p2.getHandSize()))
		cout << p2.getName() << " wins !" << endl;


	system("pause");
	return 0;
}


   



