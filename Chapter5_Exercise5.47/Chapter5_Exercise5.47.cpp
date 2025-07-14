// Chapter5_Exercise5.47.cpp : This program converts an input english phrase into
// morse code.

#include <iostream>
#include <map>
#include <string>
# include <algorithm>

using std::map;
using std::string;
using std::cout;
using std::cin;
using std::endl;

string morseCode(const string &text, const map<string, string> &morseCodeMap);

int main()
{
    // create map of english characters to morse code
    map<string, string> engToMorse;
    engToMorse["A"] = ".-";
    engToMorse["B"] = "-...";
    engToMorse["C"] = "-.-.";
    engToMorse["D"] = "-..";
    engToMorse["E"] = ".";
    engToMorse["F"] = "..-.";
    engToMorse["G"] = "--.";
    engToMorse["H"] = "....";
    engToMorse["I"] = "..";
    engToMorse["J"] = ".---";
    engToMorse["K"] = "-.-";
    engToMorse["L"] = ".-..";
    engToMorse["M"] = "--";
    engToMorse["N"] = "-.";
    engToMorse["O"] = "---";
    engToMorse["P"] = ".--.";
    engToMorse["Q"] = "--.-";
    engToMorse["R"] = ".-.";
    engToMorse["S"] = "...";
    engToMorse["T"] = "-";
    engToMorse["U"] = "..-";
    engToMorse["V"] = "...-";
    engToMorse["W"] = ".--";
    engToMorse["X"] = "-..-";
    engToMorse["Y"] = "-.--";
    engToMorse["Z"] = "--..";

    engToMorse["1"] = ".----";
    engToMorse["2"] = "..---";
    engToMorse["3"] = "...--";
    engToMorse["4"] = "....-";
    engToMorse["5"] = ".....";
    engToMorse["6"] = "-....";
    engToMorse["7"] = "--...";
    engToMorse["8"] = "---..";
    engToMorse["9"] = "----.";
    engToMorse["0"] = "-----";

    // take in English input text
    string input;
    cout << "Enter Text: ";
    std::getline(cin, input);
    cout << endl;

    // convert to morse code
    string output = "";
    int currIdx = 0;
    int nextIdx;

    while (currIdx != std::string::npos) {
        nextIdx = input.find(" ", currIdx);

        if (nextIdx != std::string::npos) {
            output.append(morseCode(input.substr(currIdx, nextIdx - currIdx), engToMorse));
            currIdx = nextIdx + 1;
        }
        else {
            output.append(morseCode(input.substr(currIdx), engToMorse));
            currIdx = nextIdx;
        }
        output.append("/");
    }

    cout << "Output: " << output << endl;

}

string morseCode(const string &word, const map<string, string>& morseCodeMap) {
    string output = "";

    // convert word to morse code
    for (int i = 0; i < word.size(); i++) {
        string c = word.substr(i, 1);
        std::transform(c.begin(), c.end(), c.begin(), ::toupper);
        if (morseCodeMap.find(c) != morseCodeMap.end()) {
            output.append(morseCodeMap.at(c));
        }
        output.append(" ");
    }

    return output;
}

