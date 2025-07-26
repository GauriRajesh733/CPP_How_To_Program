#include "Node.h"

Node::Node(Node* left, Node* right, int frequency, char character)
	: left(left), right(right), frequency(frequency), character(character)
{
}

Node::Node(int frequency, char character)
	: left(nullptr), right(nullptr), frequency(frequency), character(character)
{
}

int Node::getFrequency() const
{
	return frequency;
}

char Node::getCharacter() const
{
	return character;
}

Node* Node::getLeft() const
{
	return left;
}

Node* Node::getRight() const
{
	return right;
}
