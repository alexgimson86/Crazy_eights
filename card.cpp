#include "card.h"


//default constructor sets card to ace of spades
Card::Card()
{
	//set card to ace of spades
	rank = 1;
	suit = spades;
}
//sets card to suit and rank passed to it
Card::Card(int r, Suit s)
{
	rank = r;
	suit = s;
}
//get string for the rank that you have
string Card::rankString()const
{
	string r;

	//use switch to convert number 
	//to card rank
	switch (rank)
	{
	case 1:
		r = "A";
		break;
	case 2:
		r = "2";
		break;
	case 3:
		r = "3";
		break;
	case 4:
		r = "4";
		break;
	case 5:
		r = "5";
		break;
	case 6:
		r = "6";
		break;
	case 7:
		r = "7";
		break;
	case 8:
		r = "8";
		break;
	case 9:
		r = "9";
		break;
	case 10:
		r = "10";
		break;
	case 11:
		r = "J";
		break;
	case 12:
		r = "Q";
		break;
	case 13:
		r = "K";
	}
	
	return r;
}
//convert suit to a string
string Card::suitString()const
{
	string s;
	//switch to get suit type
	switch (suit)
	{
	case 0:
		s = "s";
		break;
	case 1:
		s = "h";
		break;
	case 2:
		s = "d";
		break;
	case 3:
		s = "c";
	}
	return s;
}
//concactenate strings and return for 
// a rank and suit type string
string Card::toString()const
{
	string fullString = rankString() + suitString();

	return fullString;
}
int Card::getRank()const
{
	return rank;
}
//return suit
Card::Suit Card::getSuit()const
{
	return suit;
}
// return true is the cards are identical
bool Card::operator== (const Card &rhs) const
{
	if (rank == rhs.rank && suit == rhs.suit)
		return true;
	else
		return false;
}