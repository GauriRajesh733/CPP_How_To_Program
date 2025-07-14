// Chapter9_MoreExercises.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "IntegerSet.h"
#include "DeckOfCards.h"
#include "Card.h"
#include <array>

using namespace std;


void run_tests();
vector<bool> tests;


int main()
{
    // INTEGER SET TESTS
    IntegerSet set1;
    //set1.displaySet();
    set1.add(1);
    set1.add(2);
    set1.add(3);
    //set1.displaySet();

    IntegerSet set2;
    set2.add(1);
    set2.add(3);

    IntegerSet unionSet = set1.unionOfSets(set2);
    //unionSet.displaySet();

    IntegerSet set3;
    set3.add(3);
    set3.add(1);

    tests.push_back(unionSet.sameSet(set3));
    tests.push_back(!set1.sameSet(set3));

    // DECK OF CARDS TESTS
    DeckOfCards deck;

    // display deck in order of initialization
    //deck.displayDeck();

    // display shuffled deck
    deck.shuffle();
    //deck.displayDeck();

    // display cards in order
    //while (deck.moreCards()) {
        //cout << "Next Card: " << deck.dealCard().toString() << endl;
    //}

    // deal poker hand
    DeckOfCards deck2;
    deck2.shuffle();
    //deck2.displayDeck();
    HandOfCards hand = deck2.dealPokerHand();

    //cout << "Poker Hand: " << endl;
    //hand.toString();

    // HAND OF CARDS TESTS

    // containsPair()
  
    // no pair
    HandOfCards hand1(Card(Card::Face::Ace, Card::Suit::Clubs),
        Card(Card::Face::Two, Card::Suit::Clubs),
        Card(Card::Face::Three, Card::Suit::Clubs),
        Card(Card::Face::Jack, Card::Suit::Clubs), 
        Card(Card::Face::Queen, Card::Suit::Clubs));
    tests.push_back(hand1.containsPair() == false);

    // pair
    HandOfCards hand2(Card(Card::Face::Ace, Card::Suit::Clubs),
        Card(Card::Face::Ace, Card::Suit::Spades),
        Card(Card::Face::Three, Card::Suit::Clubs),
        Card(Card::Face::Jack, Card::Suit::Clubs),
        Card(Card::Face::Queen, Card::Suit::Clubs));
    tests.push_back(hand2.containsPair() == true);

    // containsTwoPairs()

    // only one pair
    tests.push_back(hand2.containsTwoPairs() == false);
    
    HandOfCards hand3(Card(Card::Face::Ace, Card::Suit::Clubs),
        Card(Card::Face::Ace, Card::Suit::Spades),
        Card(Card::Face::Three, Card::Suit::Clubs),
        Card(Card::Face::Three, Card::Suit::Diamonds),
        Card(Card::Face::Queen, Card::Suit::Clubs));
    // two pairs
    tests.push_back(hand3.containsTwoPairs() == true);

    // three different types but not 2 pairs
    HandOfCards hand4a(Card(Card::Face::Ace, Card::Suit::Clubs),
        Card(Card::Face::Ace, Card::Suit::Spades),
        Card(Card::Face::Ace, Card::Suit::Diamonds),
        Card(Card::Face::Three, Card::Suit::Clubs),
        Card(Card::Face::Queen, Card::Suit::Clubs));
    tests.push_back(hand4a.containsTwoPairs() == false);

    // containsThreeOfAKind()

    // no group of three
    tests.push_back(hand3.containsThreeOfKind() == false);

    // group of three but last two have same face
    HandOfCards hand3b(Card(Card::Face::Ace, Card::Suit::Clubs),
        Card(Card::Face::Ace, Card::Suit::Spades),
        Card(Card::Face::Ace, Card::Suit::Diamonds),
        Card(Card::Face::Three, Card::Suit::Clubs),
        Card(Card::Face::Three, Card::Suit::Spades));
    tests.push_back(hand3b.containsThreeOfKind() == false);

    // group of three and last two have different face
    HandOfCards hand4(Card(Card::Face::Ace, Card::Suit::Clubs),
        Card(Card::Face::Ace, Card::Suit::Spades),
        Card(Card::Face::Ace, Card::Suit::Diamonds),
        Card(Card::Face::Three, Card::Suit::Clubs),
        Card(Card::Face::Queen, Card::Suit::Clubs));
    tests.push_back(hand4.containsThreeOfKind() == true);

    // containsFourOfKind()
    
    // only group of three
    tests.push_back(hand4.containsFourOfKind() == false);

    // group of four
    HandOfCards hand5(Card(Card::Face::Ace, Card::Suit::Clubs),
        Card(Card::Face::Ace, Card::Suit::Spades),
        Card(Card::Face::Ace, Card::Suit::Diamonds),
        Card(Card::Face::Ace, Card::Suit::Hearts),
        Card(Card::Face::Queen, Card::Suit::Clubs));
    tests.push_back(hand5.containsFourOfKind() == true);

    // containsFlush()

    // cards not all of same suit
    tests.push_back(hand5.containsFlush() == false);

    // cards all of same suit
    HandOfCards hand6(Card(Card::Face::Ace, Card::Suit::Clubs),
        Card(Card::Face::Three, Card::Suit::Clubs),
        Card(Card::Face::Two, Card::Suit::Clubs),
        Card(Card::Face::Jack, Card::Suit::Clubs),
        Card(Card::Face::Ten, Card::Suit::Clubs));
    tests.push_back(hand6.containsFlush() == true);

    // containsStraight()

    // does not contain all consecutive cards
    HandOfCards hand7(Card(Card::Face::Ace, Card::Suit::Clubs),
        Card(Card::Face::Three, Card::Suit::Spades),
        Card(Card::Face::Two, Card::Suit::Hearts),
        Card(Card::Face::Jack, Card::Suit::Diamonds),
        Card(Card::Face::Ten, Card::Suit::Diamonds));
    tests.push_back(hand6.containsStraight() == false);

    // contains all consecutive cards
    HandOfCards hand8(Card(Card::Face::Seven, Card::Suit::Clubs),
        Card(Card::Face::Nine, Card::Suit::Spades),
        Card(Card::Face::Eight, Card::Suit::Hearts),
        Card(Card::Face::Jack, Card::Suit::Diamonds),
        Card(Card::Face::Ten, Card::Suit::Diamonds));
    tests.push_back(hand8.containsStraight() == true);

    // ace-low straight
    HandOfCards hand9(Card(Card::Face::King, Card::Suit::Clubs),
        Card(Card::Face::Two, Card::Suit::Spades),
        Card(Card::Face::Ace, Card::Suit::Hearts),
        Card(Card::Face::Four, Card::Suit::Diamonds),
        Card(Card::Face::Three, Card::Suit::Diamonds));
    tests.push_back(hand9.containsStraight() == true);


    run_tests();
}

void run_tests() {
    int numFails = 0;
    for (int i = 0; i < tests.size(); i++) {
        if (!tests[i]) {
            numFails++;
            cout << "Test #" << i << " Failed!" << endl;
        }
    }

    if (numFails == 0) {
        cout << "All Tests Passed!" << endl;
    }
}
