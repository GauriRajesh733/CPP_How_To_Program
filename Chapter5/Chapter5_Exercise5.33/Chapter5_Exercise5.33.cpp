// Chapter5_Exercise5.33: Create a program that uses random number generation to create sentences

#include <iostream>
#include <iomanip>
#include <random>
#include <cctype>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;
using std::random_device;
using std::mt19937;
using std::uniform_real_distribution;

const char* randomWord(const char* WORDS[], int len, mt19937& mt, uniform_real_distribution<double>& dist);
void displaySentence(const char* SENTENCE[], const int SENTENCE_LEN);

int main()
{
	// 4 arrays of pointers to char called article, noun, verb and preposition
	const char* ARTICLE[] = { "the", "a", "one", "some", "any" };
	const char* NOUN[] = { "boy", "girl", "dog", "town", "car" };
	const char* VERB[] = { "drove", "jumped", "ran", "walked", "skipped" };
	const char* PREPOSITION[] = { "to", "from", "over", "under", "on" };
	const int ARTICLE_LEN = sizeof(ARTICLE) / sizeof(ARTICLE[0]);
	const int NOUN_LEN = sizeof(NOUN) / sizeof(NOUN[0]);
	const int VERB_LEN = sizeof(VERB) / sizeof(VERB[0]);
	const int PREPOSITION_LEN = sizeof(PREPOSITION) / sizeof(PREPOSITION[0]);

	// random
	random_device rd;
	mt19937 mt(rd());
	uniform_real_distribution<double> dist(0.0, 1.0);

	cout << "20 Random Sentences: " << endl;
	// generate 20 random sentences
	for (int i = 0; i < 20; i++) {
		// select word at random from each array in order: article, noun, verb, preposition, article, and noun
		const char* article1 = randomWord(ARTICLE, ARTICLE_LEN, mt, dist);
		const char* noun1 = randomWord(NOUN, NOUN_LEN, mt, dist);
		const char* verb = randomWord(VERB, VERB_LEN, mt, dist);
		const char* preposition = randomWord(PREPOSITION, PREPOSITION_LEN, mt, dist);
		const char* article2 = randomWord(ARTICLE, ARTICLE_LEN, mt, dist);
		const char* noun2 = randomWord(NOUN, NOUN_LEN, mt, dist);

		// concatenate words in array large enough to hold entire sentence
		// separate words by spaces
		char* article1_caps = new char[strlen(article1) + 1];
		strcpy_s(article1_caps, strlen(article1) + 1, article1);
		
		// handles characters that may be negative (unlikely but in case of non-ASCII chars with value < 0)
		article1_caps[0] = static_cast<char>(toupper(static_cast<unsigned char>(article1_caps[0])));

		const char* SENTENCE[] = { article1_caps, " ", noun1, " ", verb, " ", preposition, " ", article2, " ", noun2, "."};
		const int SENTENCE_LEN = sizeof(SENTENCE) / sizeof(SENTENCE[0]);

		// final sentence should start with capital letter and end with period
		cout << i + 1 << ". ";
		displaySentence(SENTENCE, SENTENCE_LEN);
		cout << endl;
		delete[] article1_caps;
	}
}
const char* randomWord(const char* WORDS[], int len, mt19937& random, uniform_real_distribution<double>& dist) {
	return WORDS[(int)(dist(random) * len)];
}

void displaySentence(const char* SENTENCE[], int SENTENCE_LEN) {
	for (int i = 0; i < SENTENCE_LEN; i++) {
		cout << SENTENCE[i];
	}
}
