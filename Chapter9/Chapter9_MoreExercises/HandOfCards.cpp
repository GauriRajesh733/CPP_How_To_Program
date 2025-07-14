#include "HandOfCards.h"
#include <iostream>
#include <algorithm> 
#include <exception>

using namespace std;

HandOfCards::HandOfCards(Card c1, Card c2, Card c3, Card c4, Card c5) {
	addCard(c1);
	addCard(c2);
	addCard(c3);
	addCard(c4);
	addCard(c5);
}

// add given card to this hand
void HandOfCards::addCard(Card n)
{
	if (hand.size() >= 5) {
		throw invalid_argument("Already 5 cards in hand.");
	}
	hand.push_back(n);
}

// check if this hand contains at least one pair
bool HandOfCards::containsPair()
{
	return numDifferentRanks() <= 4;
}

// check if this hand contains two pairs
bool HandOfCards::containsTwoPairs()
{
	return numDifferentRanks() == 3 && !containsGroupOf(3);
}

// check if this hand contains a pair of three and the other two have different ranks
bool HandOfCards::containsThreeOfKind()
{
	return numDifferentRanks() == 3 && containsGroupOf(3);
}

// check if this hand contains a group of 4 cards with the same rank
bool HandOfCards::containsFourOfKind()
{
	return numDifferentRanks() == 2 && containsGroupOf(4);
}

// check if all cards in this hand are from the same suit
bool HandOfCards::containsFlush()
{
	return numDifferentSuits() == 1;
}

// check if all the cards in this hand are consecutive regardless of suit
bool HandOfCards::containsStraight()
{
	vector<string> faces_with_wrap = { "Two", "Three", "Four", "Five",
		"Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace", "Two",
	"Three", "Four", "Five" };
	for (int i = 0; i <= faces_with_wrap.size() - 5; i++) {
		bool containsSequence = true;
		for (int j = i; j < i + 5; j++) {
			if (!containsFace(Card::stringToFace(faces_with_wrap[j]))) {
				containsSequence = false;
			}
		}

		if (containsSequence) {
			return true;
		}
	}

	return false;
}

void HandOfCards::toString() {
	cout << "Poker Hand: " << endl;
	for (int i = 0; i < hand.size(); i++) {
		cout << hand[i].toString() << " ";
	}
	cout << endl;	
}

int HandOfCards::numDifferentRanks()
{
	int count = 0;
	vector<Card::Face> ranks;

	for (int i = 0; i < hand.size(); i++) {
		Card::Face currentFace = hand[i].getFace();
		// check if ranks contains face of current card
		if (find(ranks.begin(), ranks.end(), currentFace)
			== ranks.end()) {
			ranks.push_back(currentFace);
		}
	}

	return ranks.size();
}

int HandOfCards::numDifferentSuits()
{
	int count = 0;
	vector<Card::Suit> suits;

	for (int i = 0; i < hand.size(); i++) {
		Card::Suit currentSuit = hand[i].getSuit();
		// check if ranks contains face of current card
		if (find(suits.begin(), suits.end(), currentSuit)
			== suits.end()) {
			suits.push_back(currentSuit);
		}
	}

	return suits.size();
}

bool HandOfCards::containsFace(Card::Face f)
{
	for (Card c : hand) {
		if (c.getFace() == f) {
			return true;
		}
	}
	return false;
}

bool HandOfCards::containsGroupOf(int n)
{
	if (n > 4 || n < 0) {
		throw invalid_argument("Invalid number of cards in face group.");
	}

	for (Card first : hand) {
		int count = 0;
		for (Card second : hand) {
			if (first.getFace() == second.getFace()) {
				count++;
			}
			if (count == n) {
				return true;
			}
		}
	}
	return false;
}
