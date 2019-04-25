#include <iostream>
#include <list>
#include <iterator>
#include <fstream>
#include <string>
#include "contact.h"
#include "contactList.h"
using namespace std;

//Constructer for list object
// ContactList::ContactList() {
//     // Contact * first = new Contact;
//     // first->setFirstName("Test");
//     // first->setLastName("Person");
//     // first->setAddress("50 Frida Kahlo Way, San Francisco, CA 94112");
//     // first->setPhoneNumber("(000)000-0000");
//     // contacts.push_back(first);
// }
ContactList::~ContactList() {
    for (Contact * c : contacts) {
        delete c;
    }    
}
//These methods are used in other methods
Contact* ContactList::getNth(const int &index) const {
    //Returns pointer to nth element
    int counter = 0;
    for (Contact * c : contacts) {
        if (counter == index) return c; 
        counter++;
    }
    //Out of range error
    return nullptr;
}
void ContactList::printList() const {
    //Prints every contact in the linked list (Names only) 
    int counter = 1; //To number contacts in output
    
    for (Contact * c : contacts) {
        cout << counter << '.' << c->getFirstName() << ' ' << c->getLastName() << endl;
        counter++;
    }  
    
}

//These methods are called by main menu 
void ContactList::addContact() {
    Contact* c = new Contact;
    string userIn; //For user input
    //First Name
    cout << "Enter the first name:" << endl;
    getline(cin, userIn);
    c->setFirstName(userIn);
    //Last Name
    cout << "Enter " << c->getFirstName() << "'s last name" << endl;
    getline(cin, userIn);
    c->setLastName(userIn);
    //Phone  Number
    cout << "Enter " << c->getFirstName() << "'s phone number" << endl;
    getline(cin, userIn);
    c->setPhoneNumber(userIn);
    //Address
    cout << "Enter " << c->getFirstName() << "'s address" << endl;
    getline(cin, userIn);
    c->setAddress(userIn);
    contacts.push_back(c);
}
void ContactList::updateContact() {
    //Update existing contact
    int choice;
    string userIn;
    cout << "Choose a contact to edit (enter a number)" << endl;
    this->printList();
    cin >> choice;
    while (choice > contacts.size() || choice < 1 || !cin) {
        //Invalid input
        if (!cin) {
           cin.clear(); //fix input stream if broken
        }
        cin.ignore(1000, '\n');
        cout << "Invalid Input - enter a valid contact number: " << endl;
        cin >> choice;
    }
    cin.ignore(1000, '\n');
    Contact* chosenCont = this->getNth(choice-1); //Chosen contact
    bool contUpdate = true; //Continue updateing
    while (contUpdate) {
        chosenCont->print();
        cout << "What do wish to change (enter a number) " << endl << "1. First name" << endl 
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
                getline(cin, userIn);
                chosenCont->setFirstName(userIn);
                break;
            case 2:
                //Update last name
                cout << "Enter the new last name: " << endl;
                getline(cin, userIn);
                chosenCont->setLastName(userIn);
                break;
            case 3:
                //Update phone number
                cout << "Enter the new phone number: " << endl;
                getline(cin, userIn);
                chosenCont->setPhoneNumber(userIn);
                cin.ignore(1000, '\n');
                break;
            case 4:
                //Update address
                cout << "Enter the new address: " << endl;
                getline(cin, userIn);
                chosenCont->setAddress(userIn);
                cin.ignore(1000, '\n');
                break;
            default:
                contUpdate = false;
        }
    }
}
void ContactList::delContact() {
    //This works by index
    int delChoice;
    cout << "Choose a contact to delete from this list (enter a number)" << endl;
    this->printList();
    cin >> delChoice;
    
    while (delChoice > contacts.size() || delChoice < 1 || !cin) {
        if (!cin) {
            cin.clear();
        }
        cin.ignore(1000, '\n');
        cout << "Invalid input - enter a valid contact number: " << endl;
        cin >> delChoice;
    }
    cin.ignore(1000, '\n'); 
    delChoice = delChoice - 1; //Makeing it the index
    int counter = 0;
    for (auto itr = contacts.begin(); itr != contacts.end(); itr++) {
        if (counter == delChoice) {
            delete *itr;
            contacts.erase(itr);
        }
        counter++;
    }
}
void ContactList::listContacts() {
    //Needs to sort first
    contacts.sort();
    //Then, print everything
    this->printList();
    //Now we ask user if they want to view one of them
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
    //If they entered a valid number, print the contact
    if (userIn <= contacts.size() && userIn >= 1) {
        this->getNth(userIn-1)->print();
    }
}
void ContactList::findContact() {
    string toFindFirst, toFindLast; //Name
    cout << "Enter the first name" << endl;
    getline(cin, toFindFirst);
    cout << "Enter the last name" << endl;
    getline(cin, toFindLast);
    for (Contact * c : contacts) {
         if (c->getFirstName() == toFindFirst && c->getLastName() == toFindLast) {
            //Found the contact
            c->print();
            return;
         }
    } 
    //If we didn't find it, tell the user
    cout << "Error: that contact does not exist" << endl;
}

void ContactList::saveList() {
    ofstream outs ("addressbook.txt");
    for (Contact * c: contacts) {
        c->save(outs);
    } 
    outs.close();    
}
void ContactList::loadList() {
    string data;
    Contact * newContact;
    ifstream ins ("addressbook.txt");
    if (ins.is_open()) {
        contacts.clear();
        while (getline(ins, data)) {
            newContact = new Contact;
            newContact->load(data);
            contacts.push_back(newContact);
        }
        ins.close();
    }
    else {
        cout << "Warning: No Contacts Loaded" << endl;
    }
} 
