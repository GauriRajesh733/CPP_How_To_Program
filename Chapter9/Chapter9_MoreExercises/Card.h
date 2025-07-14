#pragma once
#include <string>
using namespace std;

class Card
{
public:
	static const string SUITS[5];
	static const string FACES[14];

	enum class Suit {
		Clubs,
		Spades,
		Hearts,
		Diamonds,
		None
	};
	enum class Face {
		Two,
		Three,
		Four,
		Five,
		Six,
		Seven,
		Eight,
		Nine,
		Ten, 
		Queen,
		Jack,
		King,
		Ace,
		None
	};

	Card();

	Card(Face, Suit);

	string toString();

	static string faceToString(Face);

	static string suitToString(Suit);

	static Face stringToFace(string);

	static Suit stringToSuit(string);

	const Face getFace();

	const Suit getSuit();

private:
	Face face;
	Suit suit;
};

