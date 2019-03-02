#include <iostream>
#include <string>
using namespace std;

const int MAX_PEOPLE = 100;
struct Address {
    string city;
    string country;
    string street;
    string number;
    string zip;
};
struct Contact {
    string firstName;
    string lastName;
    Address address;
    string phoneNumber;
};



void sortBook(Contact addressBook[], const int &numContacts) {
    //Sorts the address book by last name (selection sort)
    //This uses simple comparison, and could be improved
    int lowest; //Index of lowest
    Contact temp; //For swaping
    for (int i=0; i<numContacts; i++) {
        lowest = i;
        for (int j=i; j<numContacts; j++) {
            if (addressBook[j].lastName < addressBook[lowest].lastName) {
                lowest = j;
            }
        }
        if (addressBook[i].lastName != addressBook[lowest].lastName) {
            temp = addressBook[i];
            addressBook[i] = addressBook[lowest];
            addressBook[lowest] = temp;
        }
    }
}
void printContact(const Contact &person) {
    //Prints out a contact
    cout << person.firstName << ' ' << person.lastName << ':' << endl;
    cout << "Address: " << person.address.number << ", " << 
        person.address.street << ", " << person.address.city << ", " << person.address.country << ", " << person.address.zip
        << endl;
    cout << "Phone Number: " << person.phoneNumber << endl;
}
void printAllContacts(Contact addressBook[], const int &numContacts) {
    for (int i=0; i<numContacts; i++) {
        cout << i+1 << '.' << addressBook[i].firstName << ' ' << addressBook[i].lastName << endl;
    }
}

void addContact(Contact addressBook[], int &numContacts) {
    //Add a contact to address book
    cout << "Enter the first name:" << endl;
    //Name
    cin >> addressBook[numContacts].firstName;
    cin.ignore(1000, '\n');
    cout << "Enter " << addressBook[numContacts].firstName << "'s last name" << endl;
    cin >> addressBook[numContacts].lastName;
    cin.ignore(1000, '\n');
    //Phone  Number
    cout << "Enter " << addressBook[numContacts].firstName << "'s phone number" << endl;
    cin >> addressBook[numContacts].phoneNumber;
    cin.ignore(1000, '\n');
    //Address
    cout << "Enter " << addressBook[numContacts].firstName << "'s house number" << endl;
    cin >> addressBook[numContacts].address.number;
    cin.ignore(1000, '\n');
    cout << "Enter " << addressBook[numContacts].firstName << "'s street" << endl;
    cin >> addressBook[numContacts].address.street;
    cin.ignore(1000, '\n');
    cout << "Enter " << addressBook[numContacts].firstName << "'s city" << endl;
    cin >> addressBook[numContacts].address.city;
    cin.ignore(1000, '\n');
    cout << "Enter " << addressBook[numContacts].firstName << "'s country" << endl;
    cin >> addressBook[numContacts].address.country;
    cin.ignore(1000, '\n');
    cout << "Enter " << addressBook[numContacts].firstName << "'s zip code" << endl;
    cin >> addressBook[numContacts].address.zip;
    cin.ignore(1000, '\n');
    numContacts++;
}
void updateContact(Contact addressBook[], int &numContacts) {
    //Update existing contact
    int choice;
    cout << "Choose a contact to edit (enter a number)" << endl; 
    printAllContacts(addressBook, numContacts);
    cin >> choice;
    while (choice > numContacts-1 || choice < 1 || !cin) {
        //Invalid input
        if (!cin) {
           cin.clear(); //fix input stream if broken
        }
        cin.ignore(1000, '\n');
        cout << "Invalid Input - enter a valid contact number: " << endl;
        cin >> choice;
    }
    cin.ignore(1000, '\n');
    int contactNum = choice-1; //Adjust for zero based index
    bool contUpdate = true; //Continue updateing
    while (contUpdate) {
        printContact(addressBook[contactNum]);
        cout << "What do you wish to change (enter a number) " << endl << "1. First name" << endl 
            << "2. Last name" << endl << "3. Phone Number" << endl << "4. Address" << endl
            << "Any other number. Stop updating this contact" << endl;
        
        cin >> choice;
        while (!cin) {
            //Invalid input
            if (!cin) {
            cin.clear(); //fix input stream if broken
            }
            cin.ignore(1000, '\n');
            cout << "Invalid Input - enter a number: " << endl;
            cin >> choice;
        }
        cin.ignore(1000, '\n');
        switch(choice) {
            case 1:
                //Update first name
                cout << "Enter the new first name: " << endl;
                cin >> addressBook[contactNum].firstName;
                cin.ignore(1000, '\n');
                break;
            case 2:
                //Update last name
                cout << "Enter the new last name: " << endl;
                cin >> addressBook[contactNum].lastName;
                cin.ignore(1000, '\n');
                break;
            case 3:
                //Update phone number
                cout << "Enter the new phone number: " << endl;
                cin >> addressBook[contactNum].phoneNumber;
                cin.ignore(1000, '\n');
                break;
            case 4:
                //Update address
                cout << "Enter the new house number: " << endl;
                cin >> addressBook[contactNum].address.number;
                cin.ignore(1000, '\n');
                cout << "Enter the new street: " << endl;
                cin >> addressBook[contactNum].address.street;
                cin.ignore(1000, '\n');
                cout << "Enter the new city: " << endl;
                cin >> addressBook[contactNum].address.city;
                cin.ignore(1000, '\n');
                cout << "Enter the new country: " << endl;
                cin >> addressBook[contactNum].address.country;
                cin.ignore(1000, '\n');
                cout << "Enter the new zip code: " << endl;
                cin >> addressBook[contactNum].address.zip;
                cin.ignore(1000, '\n');
                break;
            default:
                contUpdate = false;
        }
    }
}
void delContact(Contact addressBook[], int &numContacts) {
    //Delete existing contact
    int delChoice;
    cout << "Choose a contact to delete from this list (enter a number)" << endl;
    printAllContacts(addressBook, numContacts);
    cin >> delChoice;
    while (delChoice > numContacts-1 || delChoice <= 1 || !cin) {
        if (!cin) {
            cin.clear();
        }
        cin.ignore(1000, '\n');
        cout << "Invalid input - enter a valid contact number: " << endl;
        cin >> delChoice;
    }
    cin.ignore(1000, '\n'); 

    for (int i=delChoice-1; i<numContacts; i++) {
        addressBook[i] = addressBook[i+1];
    }
    numContacts --;
}
void listContacts(Contact addressBook[], const int &numContacts) {
    //List contacts in sorted order
    sortBook(addressBook, numContacts);
    cout << "Your contacts are: " << endl;
    printAllContacts(addressBook, numContacts);
    int userIn;
    cout << "Enter a contact number to view a contact, or any other number to return to the main menu" << endl;
    cin >> userIn;
    while (!cin) {
        if (!cin) {
            cin.clear();
        }
        cin.ignore(1000, '\n');
        cout << "Invalid input - enter a number: " << endl;
        cin >> userIn;
    }
    cin.ignore(1000, '\n');
    if (userIn <= numContacts && userIn >= 1) {
        printContact(addressBook[userIn-1]);
    }
}
void findContact(Contact addressBook[], const int numContacts) {
    //Find specific contact in book
    //Simple linear seach for now - should be updated to binary when we get the chance
    string firstName, lastName;
    cout << "Enter the first name";
    cin >> firstName;
    cin.ignore(1000, '\n');
    cout << "Enter the last name";
    cin >> lastName;
    cin.ignore(1000, '\n');

    int i = 0; //Index of contact
    bool found = false;
    do {
        if (firstName == addressBook[i].firstName && lastName == addressBook[i].lastName) {
            found = true;
        }
        else {
            i++;
        }
    } while (i < numContacts && !found);
    printContact(addressBook[i]);
}

bool mainMenu(Contact addressBook[], int &numContacts) {
    //Returns true if program should continue
    int userChoice;

    cout << "Choose numerical options." << endl;
    cout << "1. Add Contact\n2. Update Contact\n3. Delete Contact\n4. List Contact\n5. Find Contact\n6. Quit\n";
    
    cin >> userChoice;
    while (userChoice < 1 || userChoice > 6 || !cin) {
        if (!cin) {
            cin.clear();
        }
        cin.ignore(1000, '\n');
        cout << "Invalid input: enter a number between 1 and 6: ";
        cin >> userChoice;
    }
    cin.ignore(1000, '\n'); 

    switch (userChoice) {
        case 1:
            addContact(addressBook, numContacts);
            break;
        case 2:
            updateContact(addressBook, numContacts);
            break;
        case 3:
            delContact(addressBook, numContacts);
            break;
        case 4:
            listContacts(addressBook, numContacts);
            break;
        case 5:
            findContact(addressBook, numContacts);
            break;
        case 6:
            return false;
        //A default could be added here to help handle invalid inputs
    }
    return true; //If we don't quit, show menu again
}

int main() {
    Contact addressBook[MAX_PEOPLE];
    int numContacts = 0; //How many contacts are currently in addressBook
    bool cont = true; //Should the program continue
    cout << "This is your contact book" << endl;
    do {
        cont = mainMenu(addressBook, numContacts);
    } while(cont);
    return 0;
}
