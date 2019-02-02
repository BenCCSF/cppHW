#include <iostream>
#include <math.h>
//This is only used for sqrt
#include <string>
using namespace std;

void printFact(float userin, int size = 500) {
  //This function prints a factorial to cout (max output of <size> digits)
  unsigned short int num[size];
  num[0] = 1; 
  //This is an array where each element is one digit of a number this allows for long numbers, numbers are stored backwards
  //Ex: 123 would be {3, 2, 1}
  int dig = 1;
  //Number of digits in num (in use)
  int temp, carry; 
  //temp is for the product, carry is value to carry in multiplication
  float sciNot;
  //used to store scientific notation value
  
  //We multiply num by i (num starts as userin)
  for (int i = 2; i <= userin; i++) {
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
    sciNot += (num[dig-i-1]) * pow(10.0, (-1 * i));
   
  }
  cout << "This is equivalent to " << sciNot << " x 10^" << (dig - 1) << endl;
}
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
float power(float b, int x) {
  //Returns power of b^x, x cannot be fractional
  float temp = b;
  //For holding temporary value
  if (x >= 1) {
    //Positive powers
    for (int i = 1; i < x; i++) {
      temp = temp * b;
    }
  }
  else {
    //Negative powers
    for (int i = 1; i > x; i--) {
      temp = temp / b;
    }
  }
  return temp;
}
int flr(float userin) {
  //Finds floor of number
  return static_cast<int>(userin);
}
int cel(float userin) {
  //Finds ceiling of number
  if (userin > flr(userin)) {
    return (static_cast<int>(userin) + 1);
  }
  else {
    return static_cast<int>(userin);
  }
  
}
float absv(float userin) {
  //Finds absolute value of number 
  if (userin < 0) {
    return (-1.0 * userin);
  }
  else {
    return userin;
  }
}




int calculator() {
  int userin1;
  //This is where user input on what operation to use is stored
  float userin2, userin3;
  //userin2 and 3 are where user input on what numbers to preform operations on is stored. 
  
  //This function is the calculator - it is not in main because it is a recursive function
  cout << "Enter an operation key to start calculations.\nEnter -1 to exit the program.\nEnter any other character to list operation keys.\n";
  cin >> userin1;
  switch(userin1) {
    case -1:
      //Ends the program
      return 0;
    case 1:
      //Addition
      cout << "Enter the first number to add\n";
      cin >> userin2;
      cout << "Enter the second number to add\n";
      cin >> userin3;
      cout << "The sum of your numbers is: " << userin2 + userin3 << endl;
      break;
    case 2:
      //Subtraction
      cout << "Enter the first number to subtract\n";
      cin >> userin2;
      cout << "Enter the second number to subtract\n";
      cin >> userin3;
      cout << "The differnce of your numbers is: " << userin2 - userin3 << endl;
      break;
    case 3:
      //Multiplication
      cout << "Enter the first number to multiply\n";
      cin >> userin2;
      cout << "Enter the second number to multilply\n";
      cin >> userin3;
      cout << "The product of your numbers is: " << userin2 * userin3 << endl;
      break;
    case 4:
      //Division
      cout << "Enter the first number to divide\n";
      cin >> userin2;
      cout << "Enter the second number to divide\n";
      cin >> userin3;
      cout << "The quotient of your numbers is: " << userin2 / userin3 << endl;
      break;
    case 5:
      //Power
      cout << "Enter the base\n";
      cin >> userin2;
      cout << "Enter the power the base will be raised to\n";
      cin >> userin3;
      cout << "The sum of your numbers is: " << power(userin2, userin3) << endl;
      break;
    case 6:
      //Square Root 
      cout << "Enter the number you wish to take the square root of: \n";
      cin >> userin2;
      cout << "The square root of your number is " << sqrt(userin2) << endl;
      break;
    case 7:
      //Absolute Value
      cout << "Enter the number you wish to find the absolute value of\n";
      cin >> userin2;
      cout << "The absolute value of your number is " << absv(userin2) << endl;
      break;
    case 8:
      //Floor
      cout << "Enter the number you wish to find the floor of\n";
      cin >> userin2;
      cout << "The floor of your number is " << flr(userin2) << endl;
      break;
    case 9:
      //Ceiling
      cout << "Enter the number you wish to find the ceiling of\n";
      cin >> userin2;
      cout << "The ceiling of your number is " << cel(userin2) << endl;
      break;
    case 10:
      //Factorial
      cout << "Enter the number you wish to find the factorial of\n";
      cin >> userin2;
      printFact(userin2);
      break;
    default:
      menu();
  }
  calculator();
  //Using a recursive function allows the program to preform a theoretical infinate number of calculations
}

int main() {
  cout << "Welcome to a basic c++ calculator.\n";
  calculator();
  return 0;
}
