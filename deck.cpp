#include "deck.h"
#include <stdlib.h>  
#include <time.h>  
#include <cassert>

//create and shuffle a deck of cards
Deck::Deck()
{
	index = 0;
	int cardCount = 1;
	int randomNum;
	srand(time(NULL));
	Card tempCard[SIZE];

	//card count gives the card rank
	// i/13 determines what the suit will be
	for (int i = 0; i <SIZE; i++)
	{	
		if (i / 13 == 0)
		{
		    Card c(cardCount, Card::spades);
			tempCard[i] = c;
		}
		else if (i /13 == 1)
		{
		    Card c(cardCount, Card::hearts);
			tempCard[i] = c;
		}
		else if (i /13 == 2)
		{
			Card c(cardCount, Card::clubs);
			tempCard[i] = c;
		}
		else 
		{
			Card c(cardCount, Card::diamonds);
			tempCard[i] = c;
		}
		cardCount++;
		//move card rank back to one if it exceeds 13
		//since the rank is 1-13
		if (cardCount > 13)
			cardCount = 1;
	}

	//shuffle the deck
	for (int i = 0; i < SIZE; i++)
	{
		randomNum = rand() % 51;

		if (i == 0)
			cards[i] = tempCard[randomNum];
		else
		{
			for (int j = 0; j < i; j++)
			{
				if (cards[j] == tempCard[randomNum])
				{
					randomNum = rand() % 51;
					j = 0;
				}
			}
			cards[i] = tempCard[randomNum];
		}
	}
	
}
//deal a card out from the deck
Card Deck::dealCard()
{
	//make sure deck isnt empty
	assert(index < 52);
		index++;
		return cards[index - 1];
}
//return the size of the remaining deck
int Deck::size()const
{
	return SIZE - index;
}