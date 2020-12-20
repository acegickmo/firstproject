#include "Header.h"

void Deck::updateDeck() {  // erases first card in deck
    deck.erase(deck.begin());
}

void Deck::newDeck() {
    deck = freshDeck; // sets deck to the orignal deck list
}

void Deck::displayDeck() { // shows the entire contents of the deck list
    if (deck.size() == 52) {
        for (int h = 0; h < 165; ++h) {
            cout << '-';
        }
        cout << endl;
        for (int i = 0; i < 13; ++i) {
            cout << setw(13) << left << deck.at(i);
        }
        cout << endl;
        for (int j = 13; j < 26; ++j) {
            cout << setw(13) << left << deck.at(j);
        }
        cout << endl;
        for (int k = 26; k < 39; ++k) {
            cout << setw(13) << left << deck.at(k);
        }
        cout << endl;
        for (int l = 39; l < 52; ++l) {
            cout << setw(13) << left << deck.at(l);
        }
        cout << endl;
        for (int m = 0; m < 165; ++m) {
            cout << '-';
        }
        cout << "\n" << endl;
    }
}

void Deck::shuffleDeck() { // randomly rearranges the deck list
    int x;
    srand(time(NULL));
    if (deck.size() > 0) {
        for (int i = 0; i < 52; ++i) {
            x = i + (rand() % (52-i));
            swap(deck[i], deck[x]);
        }
    }
    canYouWinDeck = deck;
}
