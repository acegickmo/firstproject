
#include "Header.h"

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); // defiines handle

void menu::welcome() { // starts game and facilitates menu choices
    int choice = 0;
    SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "Welcome to Solitaire!\n" << endl;
    SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << "Select and option (1-5)\n" << endl;
    while (choice != 5) {
        SetConsoleTextAttribute(h, FOREGROUND_GREEN);
        cout << "1) New Deck\n" << "2) Display Deck\n" << "3) Shuffle Deck\n" << "4) Play Solitaire\n" << "5) Exit\n" << endl;
        cin >> choice;
        cout << endl;
        if (choice == 1) { tempHands.gameDeck.newDeck(); }
        else if (choice == 2) { tempHands.gameDeck.displayDeck(); }
        else if (choice == 3) { tempHands.gameDeck.shuffleDeck(); }
        else if (choice == 4) { playSolitaire(); }
        else if (choice == 5) { exit(); }
    }
}

void menu::playSolitaire() { // loops game, and sets up game when called
    SetConsoleTextAttribute(h, FOREGROUND_BLUE);
    tempHands.gameDeck.shuffleDeck();
    tempHands.freshHand();
    tempHands.hands.erase(tempHands.hands.begin(), tempHands.hands.begin() + tempHands.hands.size());
    if (tempHands.gameDeck.deck.size() < 52) { // checks for if deck is full
        SetConsoleTextAttribute(h, FOREGROUND_RED);
        cout << "You need to select new deck before you can play." << endl;
        SetConsoleTextAttribute(h, FOREGROUND_BLUE);
    }
    else {
        while (tempHands.gameDeck.deck.size() > 0) {
            tempHands.next();
        }
        tempHands.didYouWin();
    }
}

void menu::exit() { // quits game
    cout << "Exiting game... goodbye." << endl;
}

