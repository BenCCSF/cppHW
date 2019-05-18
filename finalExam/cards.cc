#include <iostream>
#include <fstream>
using namespace std;

const int NUM_TO_READ = 3;
// How many numbers to read from the file
const char FILE_NAME[] = "cards.txt";
//The name of the file we want to read from


int main() {
    ifstream cardData (FILE_NAME);
    string line; //For storing getline() results
    int i = 0; //Count number of files read
    if (cardData.is_open()) {
        while (getline(cardData, line) && i < NUM_TO_READ) {
            cout << line << endl; 
            i++; //This is seperate from the conditional statement for easy error testing
        }
        if (i < NUM_TO_READ) {
            //We did not all the numbers the user wanted us to read
            cout << "Warning: less than " << NUM_TO_READ << " data values found" << endl;
        }
        cardData.close();
    } 
    else {
        cout << "Error: no such file \"" << FILE_NAME << '\"' << endl;
    }
    return 0;
}
