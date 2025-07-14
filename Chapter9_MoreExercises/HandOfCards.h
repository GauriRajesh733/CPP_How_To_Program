#pragma once
#include "Card.h"
#include <vector>
#include <array>
#include "Card.h"

using namespace std;

class HandOfCards
{
public:
	HandOfCards(Card, Card, Card, Card, Card);

	bool containsPair();

	bool containsTwoPairs();

	bool containsThreeOfKind();

	bool containsFourOfKind();

	bool containsFlush();

	bool containsStraight();

	void toString();

private:
	vector<Card> hand;

	void addCard(Card);

	int numDifferentRanks();

	int numDifferentSuits();

	bool containsFace(Card::Face);

	bool containsGroupOf(int);
};

