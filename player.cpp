#include "player.h"

Player::Player()
{
	name = "blank";

}
//show the hand a player has
string Player::showHand() const
{
	string s;
	
	//create a string of all the cards in 
	//players hand
	for (int i = 0; i < hand.size(); i++)
	{
		s += hand[i].toString();
		s += " ";
	}
	return s;
}
//return hand size
int Player::getHandSize() const
{
	return hand.size();
}
//add card to the hand
void Player::addCard(Card c)
{
	
	hand.push_back(c);
}
// find out if player can play a card of same rank
bool Player::hasCardWithRank(int r, Card &c1)
{
	bool match = false;
	for (int i = 0; i < hand.size() && match == false; i++)
	{
		if (hand[i].getRank() == r)
		{
			match = true;
			c1 = hand[i];
		}
	}
	return match;
}
//find out if player has a card of same suuit to play
bool Player::hasCardWithSuit(Card::Suit s, Card &c1)
{
	bool match = false;
	for (int i = 0; i < hand.size() && match == false; i++)
	{
		if (hand[i].getSuit() == s || hand[i].getRank() == 8)
		{
			match = true;
			c1 = hand[i];
		}
	}
	return match;
}
//player plays card
bool Player::removeCardFromHand(Card c)
{
	for (int i = 0; i < hand.size(); i++)
	{
		if (c == hand[i])
		{
			hand.erase(hand.begin() + i);
			return true;
		}
	}
	return false;
}