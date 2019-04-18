#include <iostream>
#include <fstream>
#include <string>
#include "contact.h"
#include "contactList.h"
using namespace std;

//Constructer for list object
ContactList::ContactList() {
    head = new Contact();
    numContacts = 1;
    head->setFirstName("Test");
    head->setLastName("Person");
    head->setAddress("50 Frida Kahlo Way, San Francisco, CA 94112");
    head->setPhoneNumber("(000)000-0000");
}

//These methods are used in other methods
Contact* ContactList::getNth(const int &index) const {
    //Returns pointer to nth element
    Contact *iter = head; 
    int counter = 0;
    while (iter != nullptr) {
        if (counter == index) return iter; 
        counter++;
        iter = iter->getNext();
    }
    //Out of range error
    return nullptr;
}
void ContactList::printList() const {
    //Prints every contact in the linked list (Names only)
    struct Contact* iter = head;
    int counter = 1; //To number contacts in output
    while (iter != nullptr) {
        cout << counter << '.' << iter->getFirstName() << ' ' << iter->getLastName() << endl;
        counter++;
        iter = iter->getNext();
    }
}
void ContactList::sortList() {
    //Right now, this is basiclly putting all the contacts in an array and sorting that array
    //We are also not using an iter var, because we redefine head at the end - this should save a very small amount of memory
    //Put contacts in array
    Contact* addressBook[numContacts]; 
    for (int i=0; i<numContacts; i++) {
        addressBook[i] = head;
        head = head->getNext();
    }
    //Sort array
    int lowest; //Index of lowest
    Contact temp; //For swaping
    for (int i=0; i<numContacts; i++) {
        lowest = i;
        for (int j=i; j<numContacts; j++) {
            if (addressBook[j]->getLastName() < addressBook[lowest]->getLastName()) {
                lowest = j;
            }
        }
        if (addressBook[i]->getLastName() != addressBook[lowest]->getLastName()) {
            head = addressBook[i];
            addressBook[i] = addressBook[lowest];
            addressBook[lowest] = head;
        }
    }
    //Change the pointers so they are correct in the linked list
    head = addressBook[0];
    for (int i=0; i<numContacts-1; i++) {
        addressBook[i]->setNext(addressBook[i+1]);
    }
    addressBook[numContacts-1]->setNext(nullptr);
}

//These methods are called by main menu 
void ContactList::addContact() {
    Contact* iter = head; //To go through list
    while (iter->getNext() != nullptr) {
            iter = iter->getNext();
    }
    //Iter is now the last element
    //Create new Contact at end of list and make iter a pointer to it
    string userIn; //For user input

    iter->setNext(new Contact);
    iter = iter->getNext();
    //First Name
    cout << "Enter the first name:" << endl;
    getline(cin, userIn);
    iter->setFirstName(userIn);
    //Last Name
    cout << "Enter " << iter->getFirstName() << "'s last name" << endl;
    getline(cin, userIn);
    iter->setLastName(userIn);
    //Phone  Number
    cout << "Enter " << iter->getFirstName() << "'s phone number" << endl;
    getline(cin, userIn);
    iter->setPhoneNumber(userIn);
    //Address
    cout << "Enter " << iter->getFirstName() << "'s address" << endl;
    getline(cin, userIn);
    iter->setAddress(userIn);
    numContacts++;
}
void ContactList::updateContact() {
    //Update existing contact
    int choice;
    string userIn;
    cout << "Choose a contact to edit (enter a number)" << endl;
    this->printList();
    cin >> choice;
    while (choice > numContacts || choice < 1 || !cin) {
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
    if (numContacts == 1) {
        cout << "Error: cannot delete last contact" << endl;
        return;
    }
    Contact* temp;
    int delChoice;
    cout << "Choose a contact to delete from this list (enter a number)" << endl;
    this->printList();
    cin >> delChoice;
    
    while (delChoice > numContacts || delChoice < 1 || !cin) {
        if (!cin) {
            cin.clear();
        }
        cin.ignore(1000, '\n');
        cout << "Invalid input - enter a valid contact number: " << endl;
        cin >> delChoice;
    }
    cin.ignore(1000, '\n'); 
    delChoice = delChoice - 1; //Makeing it the index
    if (delChoice == 0) {
        temp = head->getNext();
        delete head;
        head = temp;
    }
    else {
        Contact* toDelPrev = this->getNth(delChoice-1);
        Contact* toDel = toDelPrev->getNext();
        toDelPrev->setNext(toDel->getNext());
        delete toDel;
    }
    numContacts--;
}
void ContactList::listContacts() {
    //Needs to sort first
    this->sortList();
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
    if (userIn <= numContacts && userIn >= 1) {
        this->getNth(userIn-1)->print();
    }
}
void ContactList::findContact() {
    string toFindFirst, toFindLast; //Name
    cout << "Enter the first name" << endl;
    getline(cin, toFindFirst);
    cout << "Enter the last name" << endl;
    getline(cin, toFindLast);
    Contact* iter = head;
    bool found = false;
    while(iter != nullptr && !found) {
        if (iter->getFirstName() == toFindFirst && iter->getLastName() == toFindLast) {
            //Found the contact
            iter->print();
            found = true;
        }
        iter = iter->getNext();
    }
    //If we didn't find it, tell the user
    if (!found) {
        cout << "Error: that contact does not exist" << endl;
    }
}

void ContactList::saveList() {
    ofstream outs ("addressbook.txt");
    Contact* iter = head;
    do {
        iter->save(outs);
        iter = iter->getNext();
    } while (iter != nullptr);
    outs.close();
    
}
void ContactList::loadList() {
    Contact* iter = head;
    string data;
    ifstream ins ("addressbook.txt");
    if (ins.is_open()) {
        if (getline(ins, data)) {
            iter->load(data);
            while (getline(ins, data)) {
                if (iter->getNext() != nullptr) {
                    iter = iter->getNext();
                    iter->load(data);
                }
                else {
                    iter->setNext(new Contact);
                    numContacts++;
                    iter = iter->getNext();
                    iter->load(data);
                    
                }
            }
        }
        
        ins.close();
    }
    else {
        cout << "Warning: No Contacts Loaded" << endl;
    }
} 
