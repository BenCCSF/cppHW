#include <iostream>
#include <string>
//String is used for passing some words between functions
using namespace std;

void menu() {
    //prints menu
    cout << "Listing operation keys in format: key. <effect>\n";
    cout << "1. Addition \n";
    cout << "2. Subtraction \n";
    cout << "3. Multiplication \n";
    cout << "4. Division \n";
    cout << "5. Power \n";
    cout << "6. Square Root \n";
    cout << "7. Absolute Value \n";
    cout << "8. Floor\n";
    cout << "9. Ceiling\n";
    cout << "10. Factorial\n";
}
void getuserIn(float &userIn1, float &userIn2, const string &mathVerb) {
    //Used for adding, subtracting, and multiplication
    //Division requires gaurding against 0, so it is seperate
    //mathVerb is read only
    cout << "Enter the first number to " << mathVerb << endl;
    cin >> userIn1;
    cout << "Enter the second number to " << mathVerb << endl;
    cin >> userIn2;
}
float findPower(float b, int x) {
    //Takes in a base (b) and a positive power (x) and returns b^x
    float temp = b;
    for (int i = 1; i < x; i++) {
        temp = temp * b;
    }
    return temp;
}
void printAdd() {
    //Adds numbers and prints the result, including the user input
    float userIn1, userIn2;
    string word = "add";
    getuserIn(userIn1, userIn2, word);
    cout << "The sum of your numbers is: " << userIn1 + userIn2 << endl;
}
void printSub() {
    //Subtracts numbers and prints with input
    float userIn1, userIn2;
    string word = "subtract";
    getuserIn(userIn1, userIn2, word);
    cout << "The sum of your numbers is: " << userIn1 - userIn2 << endl;
}
void printMult() {
    float userIn1, userIn2;
    string word = "multiply";
    getuserIn(userIn1, userIn2, word);
    cout << "The product of your numbers is: " << userIn1 * userIn2 << endl;
    
}
void printDiv() {
    float numer, denom;
    cout << "Enter the numerator" << endl;
    cin >> numer;
    do {
        //Handeling inputs of zero
        cout << "Enter the denominator (cannot be zero)" << endl;
        cin >> denom;
    } while (denom == 0);
    cout << "Your total is equal to " << numer/denom << endl;
}
void printPow() {
    //Find b^x
    float b;
    int x;
    cout << "Enter the base" << endl;
    cin >> b;
    cout << "Enter the power the base will be raised to" << endl;
    cin >> x;
    float total;
    if (x >= 1) {
        //Positive powers
        total = findPower(b, x);
    }
    else {
        //Negative powers
        total = 1.0 / findPower(b, (-1 * x));
    }
    cout << b << " raised to the power of " << x << " is " << total << endl;
}
void printSqrt() {
    double userIn;
    bool imag; //Is the number imaginary
    double root;
    cout << "Enter the number you wish to find the square root of" << endl;
    cin >> userIn; 
    if (userIn < 0) {
        imag = true;
        userIn = userIn * -1;
    }
    //Using Heron's Method of calculating square roots
    for (int i = 0; i < 7; i++) {
        root = (root + (userIn/root)) / 2;
    }
    cout << "The square root of your number is " << root;
}
void printAbs() {
    //Finds and prints absolute value
    float userIn;
    cout << "Enter the number you want to find the absolute value of" << endl;
    cin >> userIn;
    if (userIn < 0) {
        userIn = (-1.0 * userIn);
    }
    cout << "The absolute value of your number is " << userIn << endl;
}
void printFlr() {
    int userIn;
    cout << "Enter the number you want to find the floor of" << endl;
    cin >> userIn;
    //Because userIn is an int, no farther operations are required
    cout << "The floor of your number is " << userIn << endl;
}
void printCel() {
    //Prints ceiling of number
    float userIn;
    cout << "Enter the number you want to find the ceiling of" << endl;
    cin >> userIn;
    if (userIn > static_cast<int>(userIn)) {
        //The number is not a whole number
        userIn++;
    }
    cout << "The ceiling of your number is " << static_cast<int>(userIn) << endl;
}
void printFact(const int SIZE = 500) {
    //This function prints a factorial to cout (max output of <size> digits)
    int userIn;
    cout << "Enter the number you wish to find the factorial of" << endl;
    cin >> userIn;
    
    unsigned short int num[SIZE];
    num[0] = 1; 
    //This is an array where each element is one digit of a number this allows for long numbers, numbers are stored backwards
    //Ex: 123 would be {3, 2, 1}
    int dig = 1;
    //Number of digits in num (in use)
    int temp, carry; 
    //temp is for the product, carry is value to carry in multiplication
    float sciNot;
    //used to store scientific notation value
    
    //We multiply num by i (num starts as userIn)
    for (int i = 2; i <= userIn; i++) {
        //The starting value in num (1) is multiplied 
        carry = 0;
        for (int j = 0; j < dig; j++) {
            temp = i * num[j] + carry;
            num[j] = (temp % 10);
            carry = temp / 10;
        }
        while (carry) {
            //putting carry into num
            num[dig] = carry % 10;
            carry = carry / 10;
            dig ++;
        }
    }
    //Printing output
    cout << "The factorial of your number is ";
    for (int i = dig - 1; i > -1; i--) {
        cout << num[i];
    }
    cout << endl;
    //Printing in scientific notation
    sciNot = 0;
    for (int i = 0; i < 6; i ++) {
        //Change number of loops to change precision of scientific notation (more digits could cause problems with memory)
        sciNot += (num[dig-i-1]) * findPower(10.0, (-1 * i));
     
    }
    cout << "This is equivalent to " << sciNot << " x 10^" << (dig - 1) << endl;
}


bool calculator() {
    //This function is the calculator switch statment
    int userIn;
    cout << "Enter an operation key to start calculations.\nEnter -1 to exit the program.\nEnter any other character to list operation keys.\n";
    cin >> userIn;
    switch(userIn) {
        case -1:
            //Ends the program
            return false;
        case 1:
            //Addition
            printAdd();
            break;
        case 2:
            //Subtraction
            printSub();
            break;
        case 3:
            //Multiplication
            printMult();
            break;
        case 4:
            //Division
            printDiv();
            break;
        case 5:
            //Power
            printPow();
            break;
        case 6:
            //Square Root 
            printSqrt();
            break;
        case 7:
            //Absolute Value
            printAbs();
            break;
        case 8:
            //Floor
            printFlr();
            break;
        case 9:
            //Ceiling
            printCel();
            break;
        case 10:
            //Factorial
            printFact();
            break;
        default:
            menu();
    }
    return true;
}

int main() {
    cout << "Welcome to a basic c++ calculator." << endl;
    while (calculator()) {}
    //This runs calculator until it returns false, which happens when the user inputs -1 at the menu
    return 0;
}
