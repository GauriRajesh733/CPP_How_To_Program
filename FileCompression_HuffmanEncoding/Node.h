#pragma once

class Node
{
public:
	Node(Node*, Node*, int, char);
	Node(int, char);
	int getFrequency() const;
	char getCharacter() const;
	Node* getLeft() const;
	Node* getRight() const;
private:
	char character;
	Node* left;
	Node* right;
	int frequency;
};

