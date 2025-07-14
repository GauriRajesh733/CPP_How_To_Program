#pragma once
#include "Card.h"
#include "HandOfCards.h"
#include <array>
using namespace std;

class DeckOfCards
{
public:
	DeckOfCards();
	void shuffle();
	Card dealCard();
	bool moreCards();
	void displayDeck();
	HandOfCards dealPokerHand();
private:
	Card deck[52];
	int currentCard;
};

