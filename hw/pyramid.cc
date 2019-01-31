#include <iostream>
using namespace std;


int tenPow(int num) {
    //Calculates 10 ^ x
    int out = 1;
    for (int i = 0; i < num; i++) {
        out = out * 10;
    }
    return out;
}

int getUserIn() {
    //Asks user for input and returns the number they enter
    int userIn;
    bool canProceed;
    do { 
        cout << "Please enter the number of levels in your pyramid (Enter -1 to exit)" << endl;
        cin >> userIn;
        canProceed = ((userIn >= 1) && (userIn <= 7));
        if (!canProceed) {
            if (userIn == -1) {
                return userIn;
            }
            cout << "Invalid input: please enter a number between 1 and 7" << endl;
        }
    } while (!canProceed);
    return userIn;
}

void intToCharArr(long int inInt, char* arr) {
    //Now it works, but be careful of int length
    //Takes an integer and a pointer to an array of chars. Changes those chars to the numbers in the integer
    int inc = 0;
    //Tells us what index we are on
    char numHolder;
    //For holding... numbers
    while (inInt != 0) {
        numHolder = '0' + (inInt % 10);
        arr[inc] = numHolder;
        inInt = inInt / 10;
        inc ++;
        //Technically, the number is backwards, but these are all palindromes, so it doesn't matter
    }
}

long int genNumber(int num) {
    //Generates the number to be added based on level number
    //ie: 2 generates 121 and 5 generates 123454321
    long int outNum = 0;
    //For manipulation and output
    for (int i = 0; i < num; i++) {
        outNum += tenPow(i);
    }
    outNum = outNum * outNum;
    return outNum;
}

void generator() {
    //This function runs in a loop and generates the pyramids
    int levels = getUserIn();
    //Levels of pyramid
    if (levels == -1) {
        //End program
        return;
    }
    int lineWidth = ((levels * 2) - 1);
    //This holds the width of each line
    char nums[lineWidth];
    //This is for holding numbers we generate
    int lineLoc;
    //Used for holding position in line
    int whiteSpaceSize;
    //Amount of whitespace
    
    //Now we generate the characters in the array
    for (int i = 0; i < levels; i++) {
        //For every line of our pyramid...
        whiteSpaceSize = ((lineWidth - ((2 * i) + 1)) / 2);
        lineLoc = 0;
        intToCharArr(genNumber(i + 1), nums); //This puts the number we want to print this row into array nums. Length is ((2 * i) + 1)
        
        for (int j = 0; j < whiteSpaceSize; j++) {
            cout << ' ';
            lineLoc++;
        }
        for (int j = 0; j < ((2 * i) + 1); j++) {
            //This loop adds the number characters
            cout << nums[j];
            lineLoc++;
        }
        for (int j = 0; j < whiteSpaceSize; j++) {
            cout << ' ';
            lineLoc++;
        }
        cout << endl;
    }
    generator();
}

int main() {
    cout << "This program generates a pyramid!" << endl;
    generator();
    //Generator is a differnt function because I don't want to run main recursively
    
    return 0;
}
