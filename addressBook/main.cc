#include <iostream>
#include "contactList.h"
using namespace std;

/*
While this is the main file, most functionality is in the methods defined 
in contactList.cpp

Possible changes/improvments:
- change the sort function so it doesnt need an array
- make a menu object so it is 100% oop
*/

bool mainMenu(ContactList* list) {
    //Returns true if program should continue
    int userChoice; //For user input

    cout << "Choose numerical options." << endl;
    cout << "1. Add Contact\n2. Update Contact\n3. Delete Contact\n4. List Contacts\n5. Find Contact\n6. Quit\n";
    
    cin >> userChoice;
    while (userChoice < 1 || userChoice > 6 || !cin) {
        //cin returns false if it is broken (ie: user entered a 'a' into an int)
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
            list->addContact();
            break;
        case 2:
            list->updateContact();
            break;
        case 3:
            list->delContact();
            break;
        case 4:
            list->listContacts();
            break;
        case 5:
            list->findContact();
            break;
        case 6:
            return false;
    }
    return true; //If we don't quit, show menu again
}
int main() {
    ContactList* list = new ContactList();
    list->loadList();
    //List is really a pointer to our list object, which we only need one of
    bool cont = true; //Should the program continue
    cout << "This is your contact book" << endl;
    do {
        cont = mainMenu(list);
    } while(cont);
    list->saveList();
    delete list;
    return 0;
}
