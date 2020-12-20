#include "Header.h"

HANDLE a = GetStdHandle(STD_OUTPUT_HANDLE);

void hands::next() { // determines next action after the previous one was taken
    char key;

    // Draw a card
    cout << "Press D to draw a card or R to restart" << endl;
    cin >> key;

    // Add card to your hand and determine if hand is prime
    if (key == 'D') { // draws another card and updates
        updateHand();
        displayStatus();
        displayHand();
        isHandPrimeOutput();
    }
    else if (key == 'R'){ // resets game
        SetConsoleTextAttribute(a, FOREGROUND_BLUE);
        cout << "**********************************************************************************";
        cout << "\nRestarting game with a new deck.\n" << endl;
        gameDeck.newDeck();
        gameDeck.shuffleDeck();
        hands.erase(hands.begin(), hands.begin() + hands.size());
        freshHand();
    }
}

void hands::updateHand() { // Add card to your hand
    hand.push_back(cardValue(gameDeck.deck.at(0)));
    gameDeck.updateDeck();
}

bool hands::isHandPrime() { // checks for if the hand sum is prime
    int sum = 0;
    bool prime = true;

    // Calculate sum of hand
    for (unsigned i = 0; i < hand.size(); ++i) {
        sum += hand.at(i);
    }

    // Determine if hand is prime
    if (sum == 2 || sum == 3) { prime = true; }
    else if (sum == 4) { prime = false; }
    else {
        for (int j = 2; j < sum / 2; ++j) {
            if (sum % j == 0) {
                prime = false;
                break;
            }
        }
    }
    return prime;
}

void hands::isHandPrimeOutput() { // outputs to display that the hand is prime
    if (isHandPrime() == true) {
        cout << "This hand is prime!" << endl;
        cout << "----------------------------------\n\n" << endl;
        updateHands();
        if (gameDeck.deck.size() > 0) {
            freshHand();
            canYouWinOutput();
        }
    }
}

void hands::didYouWin() { // outputs win status if hand is prime
    displayStatus();
    if (isHandPrime() == true) {
        cout << "\nFinal hand is prime. You win!!" << endl;
        cout << "-------------------------------------\n\n" << endl;
    }
    else {
        cout << "Final hand is not prime. You lose." << endl;
        cout << "-------------------------------------\n\n" << endl;
    }
}

void hands::displayHand() { // lists out list of cards in hand
    int sum = 0;
    SetConsoleTextAttribute(a, FOREGROUND_GREEN);
    cout << "Current Hand: ";
    for (unsigned i = 0; i < hand.size(); ++i) {
        sum += hand.at(i);
        cout << hand.at(i) << " ";
    }
    cout << "\tSum = " << sum << "\n\n" << endl;
    SetConsoleTextAttribute(a, FOREGROUND_BLUE);
}

void hands::updateHands() { hands.push_back(hand); } // adds card to hand

void hands::freshHand() {
    hand.erase(hand.begin(), hand.begin() + hand.size()); // erases cards in hand
}

int hands::cardValue(string card) { // assigns values to all cards in hand and returns values based on card
    if (card[0] == 'A') { return 1; }
    else if (card[0] == '2') { return 2; }
    else if (card[0] == '3') { return 3; }
    else if (card[0] == '4') { return 4; }
    else if (card[0] == '5') { return 5; }
    else if (card[0] == '6') { return 6; }
    else if (card[0] == '7') { return 7; }
    else if (card[0] == '8') { return 8; }
    else if (card[0] == '9') { return 9; }
    else if (card[0] == '1') { return 10; }
    else if (card[0] == 'J') { return 10; }
    else if (card[0] == 'Q') { return 10; }
    else if (card[0] == 'K') { return 10; }
    else { return 0; }
}

void hands::displayStatus() { // displays status of game
    int sum;
    cout << "\nNumber of cards remaining:   ";
    SetConsoleTextAttribute(a, FOREGROUND_RED);
    cout << gameDeck.deck.size() << endl;
    SetConsoleTextAttribute(a, FOREGROUND_BLUE);
    cout << "Winning hands values:   ";
    SetConsoleTextAttribute(a, FOREGROUND_RED);
    for (unsigned i = 0; i < hands.size(); ++i) { // calculates sum
        sum = 0;
        for (unsigned j = 0; j < hands.at(i).size(); ++j) {
            sum += hands.at(i).at(j);
        }
        cout << (i+1) << ": " << sum << "   ";
    }
    SetConsoleTextAttribute(a, FOREGROUND_BLUE);
    cout << endl;
}

bool hands::isCanYouWinHandPrime() { // outputs status of prime in hand
    int sum = 0;
    bool prime = true;

    // Calculate sum of hand
    for (unsigned i = 0; i < canYouWinHand.size(); ++i) {
        sum += canYouWinHand.at(i);
    }

    // Determine if hand is prime
    if (sum == 2 || sum == 3) { prime = true; }
    else if (sum == 4) { prime = false; }
    else {
        for (int j = 2; j < sum / 2; ++j) {
            if (sum % j == 0) {
                prime = false;
                break;
            }
        }
    }
    return prime;
}

bool hands::canYouWin() { // checks for possiblity of winning and updates accordingly
    for (unsigned i = 0; i < gameDeck.deck.size(); ++i) {
        canYouWinHand.push_back(cardValue(gameDeck.deck.at(i)));
        if (isCanYouWinHandPrime() == true) {
            gameDeck.canYouWinDeck.erase(gameDeck.canYouWinDeck.begin(), gameDeck.canYouWinDeck.begin() + gameDeck.canYouWinDeck.size());
            canYouWinHand.erase(canYouWinHand.begin(), canYouWinHand.begin() + canYouWinHand.size());
            return true;
        }
    }
    return false;
}

void hands::canYouWinOutput() { // outputs if not possible to win
    if (canYouWin() == false) {
        SetConsoleTextAttribute(a, FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << "YOU CANNOT WIN THIS GAME\n" << endl;
    }
}
