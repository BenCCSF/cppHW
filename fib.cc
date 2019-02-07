#include <iostream>
using namespace std;

void printArr(const unsigned long long int arr[], const int &ARR_LEN) {
    //Prints an array seperated by commas
    for (int i = 0; i < ARR_LEN; i++) {
        cout << arr[i] << ", ";
    }
    cout << endl;
}


void getFact(const int &NUMS_LEN) {
    //Takes in read only number, prints factorial
    if (NUMS_LEN == 1) {
        cout << "0" << endl;
        return;
    }
    //This program cannot handle inputs of 1, so they are handled above
    unsigned long long int nums[NUMS_LEN];
    
    nums[0] = 0;
    nums[1] = 1;
    for (int i = 2; i < NUMS_LEN; i++) {
        nums[i] = nums[i-1] + nums[i-2];
    }
    printArr(nums, NUMS_LEN);
    
}

void getUserIn(int &outNum) {
    //Gets the user's number and puts it in outNum
    while (true) {
        cout << "Enter a number:" << endl;
        cin >> outNum;
        //BUG: Entering a character that is not a number crashes everything (or outside of an integer)
        if (outNum > 0 && outNum < 95) { //The highest fib number a unsigned long long int can hold is the 94th
            return;
        }
        else {
            cout << "Enter a valid number (Between 0 and 95)" << endl;
        }
    }
}

void getUserIn(bool &moveForward) {
    //Asks user if they want the program to keep running
    char userIn;
    while (true) {
        cout << "Continue (y/n)" << endl;
        cin >> userIn;
        if (userIn == 'n') {
            moveForward = false;
            return;
        }
        else if (userIn == 'y') {
            return; //moveForward is true by default, so we don't need to change it
        }
        else {
            cout << "Error: Invalid input: Please enter 'y' or 'n'" << endl;
        }
    }
}

int main() {
    int inNum;
    bool keepRunning = true;
    while (keepRunning) {
        getUserIn(inNum);
        getFact(inNum);
        getUserIn(keepRunning);
    }
}
