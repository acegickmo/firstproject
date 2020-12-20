
#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <ctime>
#include <Windows.h>

using namespace std;

class Deck { // defines deck class which starts with a full deck of cards
    public:
        vector<string> deck;
        const vector<string> freshDeck = {"A-Spade", "2-Spade", "3-Spade", "4-Spade", "5-Spade", "6-Spade", "7-Spade", "8-Spade", "9-Spade", "10-Spade", "J-Spade", "Q-Spade", "K-Spade",
                                          "A-Heart", "2-Heart", "3-Heart", "4-Heart", "5-Heart", "6-Heart", "7-Heart", "8-Heart", "9-Heart", "10-Heart", "J-Heart", "Q-Heart", "K-Heart",
                                          "A-Club", "2-Club", "3-Club", "4-Club", "5-Club", "6-Club", "7-Club", "8-Club", "9-Club", "10-Club", "J-Club", "Q-Club", "K-Club",
                                          "A-Diamond", "2-Diamond", "3-Diamond", "4-Diamond", "5-Diamond", "6-Diamond", "7-Diamond", "8-Diamond", "9-Diamond", "10-Diamond", "J-Diamond", "Q-Diamond", "K-Diamond"};

        vector<string> canYouWinDeck;
        void updateDeck();
        void newDeck();
        void displayDeck();
        void shuffleDeck();
};

class hands { // defines hands class, which uses cards that have been drawn from the deck
    public:
        void next();
        void displayStatus();
        void didYouWin();
        void freshHand();
        Deck gameDeck;
        vector<int> hand;
        vector<vector<int>> hands;
    private:
        vector<int> canYouWinHand;
        void updateHand();
        bool isHandPrime();
        void isHandPrimeOutput();
        void displayHand();
        void updateHands();
        int cardValue(string card);
        bool isCanYouWinHandPrime();
        bool canYouWin();
        void canYouWinOutput();
};

class menu { // defines menu class, which handles the display of the game
    public:
        void welcome();
        hands tempHands;
    private:
        void playSolitaire();
        void exit();
};

#endif // HEADER_H
