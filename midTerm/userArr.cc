#include <iostream>
using namespace std;

void getNum(int &target) {
    //Takes a number as input from the user: stores in int
    cin >> target;
    while (!cin) {
        //Cin error handleing
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Please enter a valid number" << endl;
        cin >> target;
    }
    cin.ignore(1000, '\n');
}
void getNum(float &target) {
    //Takes a number as input from the user: stores in float
    cin >> target;
    while (!cin) {
        //Cin error handleing
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Please enter a valid number" << endl;
        cin >> target;
    }
    cin.ignore(1000, '\n');
}

int main() {
    int arrLen;
    cout << "How many numbers would you like to enter? " << endl;
    getNum(arrLen);
    float arr[arrLen];
    for (int i=0; i<arrLen; i++) {
        cout << "Enter a number: ";
        getNum(arr[i]);
    }
    //Now print the array
    cout << "You entered: " << endl;
    for (int i=0; i<arrLen; i++) {
        cout << arr[i] << ", ";
    }
    cout << endl;
    return 0;
}
