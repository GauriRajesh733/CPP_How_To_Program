#include "Card.h"
const string Card::SUITS[5] = {"Clubs", "Spades", "Hearts", "Diamonds", "None"};
const string Card::FACES[14] = { "Two", "Three", "Four", "Five",
		"Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace", "None"};

Card::Card()
{
	face = Card::Face::None;
	suit = Card::Suit::None;
}

Card::Card(Card::Face f, Card::Suit s)
{
	face = f;
	suit = s;
}

string Card::toString()
{
	return faceToString(face) + " of " + suitToString(suit);
}

string Card::faceToString(Face f)
{
	switch (f) {
		case Card::Face::Two:
			return Card::FACES[0];
		case Card::Face::Three:
			return Card::FACES[1];
		case Card::Face::Four:
			return Card::FACES[2];
		case Card::Face::Five:
			return Card::FACES[3];
		case Card::Face::Six:
			return Card::FACES[4];
		case Card::Face::Seven:
			return Card::FACES[5];
		case Card::Face::Eight:
			return Card::FACES[6];
		case Card::Face::Nine:
			return Card::FACES[7];
		case Card::Face::Ten:
			return Card::FACES[8];
		case Card::Face::Jack:
			return Card::FACES[9];
		case Card::Face::Queen:
			return Card::FACES[10];
		case Card::Face::King:
			return Card::FACES[11];
		case Card::Face::Ace:
			return Card::FACES[12];
		default:
			return Card::FACES[13];
	}
}

string Card::suitToString(Suit s)
{
	switch (s) {
		case Card::Suit::Clubs:
			return Card::SUITS[0];
		case Card::Suit::Spades:
			return Card::SUITS[1];
		case Card::Suit::Hearts:
			return Card::SUITS[2];
		case Card::Suit::Diamonds:
			return Card::SUITS[3];
		default:
			return Card::SUITS[4];
	}
}

Card::Face Card::stringToFace(string f)
{
	if (f == Card::FACES[0]) {
		return Card::Face::Two;
	}
	else if (f == Card::FACES[1]) {
		return Card::Face::Three;
	}
	else if (f == Card::FACES[2]) {
		return Card::Face::Four;
	}
	else if (f == Card::FACES[3]) {
		return Card::Face::Five;
	}
	else if (f == Card::FACES[4]) {
		return Card::Face::Six;
	}
	else if (f == Card::FACES[5]) {
		return Card::Face::Seven;
	}
	else if (f == Card::FACES[6]) {
		return Card::Face::Eight;
	}
	else if (f == Card::FACES[7]) {
		return Card::Face::Nine;
	}
	else if (f == Card::FACES[8]) {
		return Card::Face::Ten;
	}
	else if (f == Card::FACES[9]) {
		return Card::Face::Jack;
	}
	else if (f == Card::FACES[10]) {
		return Card::Face::Queen;
	}
	else if (f == Card::FACES[11]) {
		return Card::Face::King;
	}
	else if (f == Card::FACES[12]) {
		return Card::Face::Ace;
	}
	else {
		return Card::Face::None;
	}
}

Card::Suit Card::stringToSuit(string s)
{
	if (s == Card::SUITS[0]) {
		return Card::Suit::Clubs;
	}
	else if (s == Card::SUITS[1]) {
		return Card::Suit::Spades;
	}
	else if (s == Card::SUITS[2]) {
		return Card::Suit::Hearts;
	}
	else if (s == Card::SUITS[3]) {
		return Card::Suit::Diamonds;
	}
	else {
		return Card::Suit::None;
	}
}

const Card::Face Card::getFace()
{
	return face;
}

const Card::Suit Card::getSuit()
{
	return suit;
}


