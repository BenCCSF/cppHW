#include <iostream>
using namespace std;


void printArr(int arr[], const int &ARR_SIZE) {
    for (int i=0; i<ARR_SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void putInDeck(int deck[], const int pile1[], const int pile2[], const int pile3[], const int &PILE_SIZE) {
    //Puts the piles in the deck, in order they are recived
    for (int i=0; i<PILE_SIZE; i++) {
        deck[i] = pile1[i];
    }
    for (int i=0; i<PILE_SIZE; i++) {
        deck[i+7] = pile2[i];
    }
    for (int i=0; i<PILE_SIZE; i++) {
        deck[i+14] = pile3[i];
    }
}

void pilePhase(int deck[]) {
    //This seperate the deck into piles, asks the user to identify the correct pile, and puts the piles back in the deck in order
    const int NUM_PILES = 3;
    const int PILE_SIZE = 7;
    int piles[NUM_PILES][PILE_SIZE];
    int userIn;
    
    //The below for loop takes the deck and seperates it into piles (2d array)
    for (int i=0; i<7; i++ ) {
        for (int j=0; j<3; j++) {
            piles[j][i] = deck[((3 * i) + j)];
            //3i + j calculates the index of the next value in deck to take from
        }
    }
    //Print the piles
    for (int i=0; i<3; i++) {
        cout << "PILE " << i+1 << ": ";
        printArr(piles[i], 7);
    }
    //Now get the user to say what bucket their number is in
    do {
        cout << "Please Identify which pile your number is in (1, 2, or 3): ";
        cin >> userIn;
        if (!cin) {
            //User input error handling
            cin.clear();
            userIn = 0;
        }
        cin.ignore(10000, '\n'); //Clearing excess chars in stream
    } while (!((userIn <=3) && (userIn >= 1)));
    
    putInDeck(deck, piles[userIn==1 ? 1:0], piles[userIn-1], piles[userIn==3 ? 1:2], PILE_SIZE);
    //The order in which piles are passed is the order they are added
    //If userIn is one (aka piles[0]), piles[0] and piles[1] swap places
    //If userIn is three (aka piles[2]), piles[2] and piles[1] swap places
}

void intro(int deck[], const int &DECK_SIZE) {
    //Generates deck and asks user to think of number
    //First we generate the deck
    for (int i=0; i<DECK_SIZE; i++) {
        deck[i] = i + 1;
    }
    printArr(deck, DECK_SIZE);
    //Now we talk to user and ask to continue
    bool userIn;
    cout << "Chose one of the numbers displayed above (Remember it, but do not enter it)" << endl;
    do {
        cout << "Press 0 to continue: ";
        cin >> userIn;
        if (!cin) {
            //User input error handleing
            cin.clear();
            userIn = true;
        }
        cin.ignore(10000, '\n'); //Clearing excess chars in stream
    } while(userIn);
}

bool checkNumAndCont(const int deck[]) {
    char userIn;
    cout << "Is your number " << deck[10] << "? (y/n)" << endl;
    cin >> userIn;
    while (((userIn != 'y') && (userIn != 'n')) || (!cin)) {
        //This loop triggers on any kind of invalid input or cin error
        //Clear input to fix broken things first
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid input: Please enter 'y' or 'n': ";
        cin >> userIn;
        cout << endl;
    }
    if (userIn == 'y') {
        cout << "The ancient magic known as mathmatics has worked on you" << endl;
    }
    else {
        cout << "Congratulations! Either you are lying or have broken this algorithm" << endl;
    }
    cout << "Continue? (y/n)" << endl;
    cin >> userIn;
    while (((userIn != 'y') && (userIn != 'n')) || (!cin)) {
        //This loop triggers on any kind of invalid input or cin error
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid input: Please enter 'y' or 'n': ";
        cin >> userIn;
        cout << endl;
    }
    return (userIn == 'y');
}


int main() {
    const int DECK_SIZE = 21;
    int deck[DECK_SIZE];
    bool cont; //Should the program keep repeating?
    
    do {
        intro(deck, DECK_SIZE); //Print out initial deck and ask for user to continue
        for (int i=0; i<3; i++) {
            pilePhase(deck);
        }
        cont = checkNumAndCont(deck);
    } while (cont);

    return 0;
}
