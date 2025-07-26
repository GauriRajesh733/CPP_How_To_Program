// FileCompression_HuffmanEncoding.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <map>
#include <vector>
#include <list>
#include <algorithm>

#include "Node.h"

enum class Choice { ENCODE=1, DECODE, EXIT };

void encode();

void decode();

Choice getChoice();


void createCodes(std::map<char, std::string>&, Node&, std::string);

bool compareNodes(const Node* node1, const Node* node2) {
	return node1->getFrequency() < node2->getFrequency();
}


int main(int argc, char* argv[])
{

	Choice choice;

	while ((choice = getChoice()) != Choice::EXIT) {
		switch (choice) {
			case(Choice::ENCODE):
				encode();
				break;
			case(Choice::DECODE):
				decode();
				break;
			default:
				std::cout << "Invalid choice, please enter a valid choice (1,2, or 3).\n";
				std::cin.clear();
				break;
		}
		std::cout << std::endl;
	}
	
	
}

void createCodes(std::map<char, std::string>& codeWords, Node& node, std::string accumCode) {
	// reached leaf node
	if (node.getLeft() == nullptr && node.getRight() == nullptr) {
		codeWords.insert(std::pair<char, std::string>(node.getCharacter(), accumCode));
	}
	if (node.getLeft() != nullptr) {
		createCodes(codeWords, *node.getLeft(), accumCode + "0");
	}
	if (node.getRight() != nullptr) {
		createCodes(codeWords, *node.getRight(), accumCode + "1");
	}
}

void encode()
{
	// get file to encode
	std::string encodedFilePath;
	std::cout << "Enter full path of text file to be encoded: ";
	std::cin >> encodedFilePath;

	std::ifstream file{ encodedFilePath, std::ios::in };

	if (!file) {
		std::cerr << "Cannot find file with given path." << std::endl;
		return;
	}

	file.seekg(0);
	std::map<char, int> frequencies;
	std::list<Node*> nodes;

	// get frequencies of characters in file
	char currentChar{};
	while (file.get(currentChar)) {
		if (frequencies.find(currentChar) == frequencies.end()) {
			frequencies.insert(std::pair<char, int>(currentChar, 1));
		}
		else {
			frequencies[currentChar]++;
		}
	}


	// add all nodes with frequencies
	for (const auto& pair : frequencies) {
		nodes.push_back(new Node(pair.second, pair.first));
		//std::cout << pair.first << ": " << pair.second << std::endl;
	}

	// create min heap based on node frequencies
	while (nodes.size() > 1) {
		nodes.sort(compareNodes);

		auto it = nodes.begin();
		Node* first = *it;
		it++;
		Node* second = *it;
		nodes.erase(nodes.begin());
		nodes.erase(nodes.begin());

		int frequency = first->getFrequency() + second->getFrequency();
		nodes.push_back(new Node(first, second, frequency, '$'));
	}

	// traverse tree to establish code words
	std::map<char, std::string> codeWords;
	Node* root = nodes.front();
	createCodes(codeWords, *root, "");

	// encode file
	std::ofstream outputFile{ encodedFilePath + "_encoded.txt" };
	if (!outputFile.is_open()) {
		std::cerr << "Unable to open file with encoded data." << std::endl;
		exit(EXIT_FAILURE);
	}

	file.clear();
	file.seekg(0);
	outputFile.seekp(0);

	while (file.get(currentChar)) {

		if (codeWords.find(currentChar) == codeWords.end()) {
			std::cerr << "Something went wrong, text was not properly encoded." << std::endl;
			return;
		}
		outputFile << codeWords[currentChar];
	}

	// decoding dictionary file
	std::ofstream dictionaryFile{ encodedFilePath + "_decoding_dictionary.txt" };

	if (!dictionaryFile.is_open()) {
		std::cerr << "Unable to open decoding dictionary file." << std::endl;
		exit(EXIT_FAILURE);
	}
	
	dictionaryFile.seekp(0);

	for (const auto word : codeWords) {
		dictionaryFile << static_cast<int>(word.first) << ' ' << word.second << '\n';
	}

	std::cout << "File succesfully encoded!\nEncoded data stored in " << encodedFilePath + "_encoded.txt.\n"
		<< "Decoding dictionary stored in " << encodedFilePath + "_decoding_dictionary.txt\n";

	for (Node* node : nodes) {
		delete node;
	}

	nodes.clear();
	file.close();
	outputFile.close();
}

void decode()
{

	// get file to decode
	std::string fileToDecodePath;
	std::cout << "Enter full path of text file to be decoded: ";
	std::cin >> fileToDecodePath;

	std::ifstream fileToDecode{ fileToDecodePath, std::ios::in };

	if (!fileToDecode) {
		std::cerr << "Cannot find file to decode with given path." << std::endl;
		return;
	}

	// get file with code words
	std::string dictionaryPath;
	std::cout << "Enter full path of text file with decoding dictionary: ";
	std::cin >> dictionaryPath;

	std::ifstream decodeDictionary{ dictionaryPath, std::ios::in };

	if (!decodeDictionary) {
		std::cerr << "Cannot find file to decode with given path." << std::endl;
		return;
	}

	std::map<std::string, char> codeWords;

	// add code words from file
	int asciiChar;
	std::string code;
	while (decodeDictionary >> asciiChar >> code) {
		codeWords[code] = static_cast<char>(asciiChar);
		//std::cout << code << ", " << codeWords[code] << std::endl;
	}

	// decode file
	fileToDecode.clear();
	fileToDecode.seekg(0);
	std::string currentCodeWord = "";
	std::string decodedData = "";
	char currentChar{};

	while (fileToDecode.get(currentChar)) {
		currentCodeWord += currentChar;

		if (codeWords.find(currentCodeWord) != codeWords.end()) {
			decodedData += codeWords[currentCodeWord];
			currentCodeWord = "";
		}
	}

	std::cout << "Decoded Data: " << decodedData << std::endl;
	decodeDictionary.close();
	fileToDecode.close();
}

Choice getChoice() {
	std::cout << "\nEnter your choice\n"
		<< "1 - Encode\n"
		<< "2 - Decode\n"
		<< "3 - Exit\n";

	int menuChoice;
	std::cin >> menuChoice;

	return static_cast<Choice>(menuChoice);
}


