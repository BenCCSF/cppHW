#include <iostream>
#include <math.h>
using namespace std;

//Global varibles 
int userin1;
//This is where user input on what operation to use is stored
unsigned long long int fact;
//fact is used in factorial calculations and factorials can be long - thus the type long int - also factorials are positive, thus unsigned
float userin2, userin3;
//userin2 and 3 are where user input on what numbers to preform operations on is stored. 

int calculator() {
  //This function is the calculator - it is not in main because it is a recursive function
  cout << "Enter an operation key to start calculations.\nEnter -1 to exit the program.\nEnter any other character to list operation keys.\n";
  cin >> ::userin1;
  switch(::userin1) {
    case -1:
      //Ends the program
      return 0;
    case 1:
      //Addition
      cout << "Enter the first number to add\n";
      cin >> ::userin2;
      cout << "Enter the second number to add\n";
      cin >> ::userin3;
      cout << "The sum of your numbers is: " << ::userin2 + ::userin3 << endl;
      break;
    case 2:
      //Subtraction
      cout << "Enter the first number to subtract\n";
      cin >> ::userin2;
      cout << "Enter the second number to subtract\n";
      cin >> ::userin3;
      cout << "The differnce of your numbers is: " << ::userin2 - ::userin3 << endl;
      break;
    case 3:
      //Multiplication
      cout << "Enter the first number to multiply\n";
      cin >> ::userin2;
      cout << "Enter the second number to multilply\n";
      cin >> ::userin3;
      cout << "The product of your numbers is: " << ::userin2 * ::userin3 << endl;
      break;
    case 4:
      //Division
      cout << "Enter the first number to divide\n";
      cin >> ::userin2;
      cout << "Enter the second number to divide\n";
      cin >> ::userin3;
      cout << "The quotient of your numbers is: " << ::userin2 / ::userin3 << endl;
      break;
    case 5:
      //Power
      cout << "Enter the base\n";
      cin >> ::userin2;
      cout << "Enter the power the base will be raised to\n";
      cin >> ::userin3;
      cout << "The sum of your numbers is: " << pow(::userin2, ::userin3) << endl;
      break;
    case 6:
      //Square Root 
      cout << "Enter the number you wish to take the square root of: \n";
      cin >> ::userin2;
      cout << "The square root of your number is " << sqrt(::userin2) << endl;
      break;
    case 7:
      //Absolute Value
      cout << "Enter the number you wish to find the absolute value of\n";
      cin >> ::userin2;
      cout << "The absolute value of your number is " << abs(::userin2) << endl;
      break;
    case 8:
      //Floor
      cout << "Enter the number you wish to find the floor of\n";
      cin >> ::userin2;
      cout << "The floor of your number is " << floor(::userin2) << endl;
      break;
    case 9:
      //Ceiling
      cout << "Enter the number you wish to find the ceiling of\n";
      cin >> ::userin2;
      cout << "The ceiling of your number is " << ceil(::userin2) << endl;
      break;
    case 10:
      //Factorial
      cout << "Enter the number you wish to find the factorial of\n";
      cin >> ::userin2;
      ::fact = static_cast<int>(::userin2);
      for (int i = 1; i < ::userin2; ++i) {
        ::fact *= i; 
      }
      cout << "The factorial of your number is " << ::fact << endl;
      break;
    default:
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
  calculator();
  //Using a recursive function allows the program to preform a theoretical infinate number of calculations
  return 0;
}

int main() {
  cout << "Welcome to a basic c++ calculator.\n";
  calculator();
  return 0;
}
