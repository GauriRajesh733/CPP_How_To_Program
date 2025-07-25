// PhishingScanner.cpp: This program uses a list of 30 words commonly found in phishing messages.  
// Each term is assigned a point value based on its likeliness to be in a phishing message.  
// The score breakdown is as follows:
// 1: somewhat likely; 2: moderately likely; 3: highly likely
// This program scans a file of text for these terms, prints the 
// occurrences of each keyword or phrase, and displays the total points for the entire message.

#include <iostream>
#include <map>
#include <fstream>
#include <algorithm>
#include <cctype>

int main()
{
    // set keywords for scanning phishing messages
    std::map<std::string, int> keywords;
    std::map<std::string, int> occurrences;
    int finalScore = 0;
    
    // terms
    keywords["locked"] = 3;
    keywords["immediate"] = 3;
    keywords["final"] = 2;
    keywords["won"] = 3;
    keywords["gift"] = 3;
    keywords["free"] = 2;
    keywords["verify"] = 2;
    keywords["customer"] = 1;
    keywords["confirm"] = 1;
    keywords["account"] = 1;
    keywords["urgent"] = 3;
    keywords["important"] = 3;
    keywords["suspended"] = 3;
    keywords["invoice"] = 3;
    keywords["security"] = 3;
    keywords["alert"] = 2;
    keywords["netflix"] = 2;
    keywords["hello"] = 1;
    keywords["free"] = 1;
    keywords["login"] = 1;
    keywords["paypal"] = 2;
    keywords["walmart"] = 2;
    keywords["ups"] = 2;
    keywords["instagram"] = 2;
    keywords["x"] = 2;
    keywords["apple"] = 2;
    keywords["fedex"] = 2;
    keywords["microsoft"] = 3;
    keywords["google"] = 3;
    keywords["linkedin"] = 3;

    // set occurrences to 0
    for (const auto& pair : keywords) {
        occurrences[pair.first] = 0;
    }

    std::ifstream susfile("sus.txt", std::ios::in);

    if (!susfile) {
        std::cerr << "File could not be opened" << std::endl;
        exit(EXIT_FAILURE);
    }

    susfile.seekg(0);

    std::string currentWord;
    while (susfile >> currentWord) {
        // change word to lowercase and remove non-alphanumeric characters
        std::transform(currentWord.begin(), currentWord.end(), currentWord.begin(), ::tolower);
        currentWord.erase(std::remove_if(currentWord.begin(), currentWord.end(),
            [](unsigned char c) {
                return !std::isalnum(c);
            }),
            currentWord.end());

        std::cout << "current word: " << currentWord << std::endl;
        // increment keyword occurrences if found in file message
        if (keywords.find(currentWord) != keywords.end()) {
            occurrences[currentWord]++;
            finalScore += keywords[currentWord];
        }
    }

    // display occurrences
    for (const auto& pair : occurrences) {
        if (pair.second != 0) {
            std::cout << "Keyword " << pair.first << " was found " << pair.second << " times in the message." << std::endl;
        }
    }

    std::cout << "Final Score: " << finalScore << std::endl;
}