#include <iostream>
#include "patientAccount.h"
using namespace std;

void checkOut(PatientAccount* pat) {
    //Assuming patient is selected
    int userChoice;
    bool cont = true; //Do we keep showing the menu?
    while  (cont) {
        cout << "Chose an option from the numerical choices below" << endl;
        cout << "1. Add surgery cost" << endl
            << "2. Add pharmacy cost" << endl
            << "3. Edit duration of patient stay" << endl
            << "4. Proceed to patient billing and checkout" << endl;
        cin >> userChoice;
        while (!cin || (userChoice < 1) || (userChoice > 4)) {
            cout << "Error: Invalid input (Select a number between 1 and 4)";
            cin.clear();
            cin.ignore(1000, '\n');
            cin >> userChoice;
        } 
        switch (userChoice) {
            case 1:
                pat->addSurgeryCost();
                break;
            case 2:
                pat->addPharmaCost();
                break;
            case 3:
                cout << "Records show that this patient has been at the hospital for " << pat->getDays() << endl;
                cout << "Enter the new value: " << endl;
                cin >> userChoice;
                while (!cin) {
                    cout << "Error: Invalid Input: Enter a new number" << endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cin >> userChoice;
                }
                pat->setDays(userChoice);
                break;
            case 4:
                cont = false; 
        }
    }
    //Now we display cost
    cout << "The services provided cost the patient a total of $" <<pat->getTotalCost() << endl;
}

int main() {
    bool cont = true; //Do we keep going?
    char userIn;
    PatientAccount* patient;
    cout << "Welcome to a hospital billing calculator" << endl;
    while (cont) {
        patient = new PatientAccount();
        checkOut(patient);
        delete patient;
        cout << "Would you like to keep billing patients? (y/n)" << endl;
        cin >> userIn;
        cin.ignore(1000, '\n');
        while (userIn != 'n' && userIn != 'y') {
            cout << "Error: Please enter 'y' or 'n'" << endl;
            cin >> userIn;
            cin.ignore(1000, '\n');
        }
        if (userIn == 'n') cont = false;
    }
    return 0;
}
