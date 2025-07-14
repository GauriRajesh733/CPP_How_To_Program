#include "DeckOfCards.h"
#include "Card.h"
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <exception>
#include <array>

DeckOfCards::DeckOfCards()
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			deck[i * 13 + j] = Card(Card::stringToFace(Card::FACES[j]),
				Card::stringToSuit(Card::SUITS[i]));
		}
	}
	currentCard = 0;
}

void DeckOfCards::shuffle()
{
	int card1Idx;
	int card2Idx;

	for (int i = 0; i < 52; i++) {
		card1Idx = rand() % 52;
		card2Idx = rand() % 52;

		swap(deck[card1Idx], deck[card2Idx]);
	}
}

Card DeckOfCards::dealCard()
{
	return deck[currentCard++];
}

bool DeckOfCards::moreCards()
{
	return currentCard < 52;
}

void DeckOfCards::displayDeck()
{
	cout << "Deck: ";
	for (int i = 0; i < 52; i++) {
		cout << deck[i].toString() << endl;
	}
	cout << endl;
}

HandOfCards DeckOfCards::dealPokerHand()
{
	if (currentCard > 47) {
		throw invalid_argument("Not enough cards to deal poker hand.");
	}

	vector<Card> handCards;
	//cout << "Dealing Cards: " << endl;
	for (int i = 0; i < 5; i++) {
		handCards.push_back(dealCard());
	}

	return HandOfCards(handCards[0], handCards[1], handCards[2], 
		handCards[3], handCards[4]);
}

