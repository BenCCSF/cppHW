#include <iostream>
#include <string>
using namespace std;
/*
Some General notes:
- Head is always passed by reference, so be careful about changing it
- I think that we don't need to ignore after takeing in a string with cin, but more testing might be good (right now it doesn't break anything, so I'm keeping it until we test more)
*/
struct Contact {
    struct Contact* next;
    string firstName;
    string lastName;
    string address;
    string phoneNumber;
};
struct Contact* getNth(struct Contact* const head, const int &index) {
    //Returns a pointer to the nth contact
    struct Contact* iter = head;
    int counter = 0;
    while (iter != nullptr) {
        if (counter == index) return iter;
        counter++;
        iter = iter->next;
    }
    //Out of range error
    return nullptr;
}
int getNumContacts(struct Contact* const &head) {
    // Returns the number of contacts
    int counter = 0;
    struct Contact* iter = head;
    while (iter != nullptr) {
        counter++;
        iter = iter->next;
    }
    return counter;
}

void sortBook(struct Contact* &head) {
    //Right now, this is basiclly putting all the contacts in an array and sorting that array
    //Put contacts in array
    struct Contact* iter = head;
    int numContacts = getNumContacts(head);
    struct Contact* addressBook[numContacts]; 
    for (int i=0; i<numContacts; i++) {
        addressBook[i] = iter;
        iter = iter->next;
    }
    //Sort array
    int lowest; //Index of lowest
    Contact temp; //For swaping
    for (int i=0; i<numContacts; i++) {
        lowest = i;
        for (int j=i; j<numContacts; j++) {
            if (addressBook[j]->lastName < addressBook[lowest]->lastName) {
                lowest = j;
            }
        }
        if (addressBook[i]->lastName != addressBook[lowest]->lastName) {
            iter = addressBook[i];
            addressBook[i] = addressBook[lowest];
            addressBook[lowest] = iter;
        }
    }
    //Change the pointers so they are correct in the linked list
    head = addressBook[0];
    for (int i=0; i<numContacts-1; i++) {
        addressBook[i]->next = addressBook[i+1];
    }
    addressBook[numContacts-1]->next = nullptr;
}
void printContact(struct Contact* const &contact) {
    //Takes in the contact that it needs to print and prints it (all info)
    cout << contact->firstName << ' ' << contact->lastName << ':' << endl;
    cout << "Address: " << contact->address << endl;
    cout << "Phone Number: " << contact->phoneNumber << endl;
}
void printAllContacts(struct Contact* const &head) {
    //Prints every contact in the linked list (Names only)
    struct Contact* iter = head;
    int counter = 1; //To number contacts in output
    while (iter != nullptr) {
        cout << counter << '.' << iter->firstName << ' ' << iter->lastName << endl;
        counter++;
        iter = iter->next;
    }
}
void addContact(struct Contact* &head) {
    struct Contact* iter = head; //To go through list
    while (iter->next != nullptr) {
            iter = iter-> next; //Iter is now last element
    }
    //Create new Contact at end of list and make iter a pointer to it
    iter->next = new Contact;
    iter = iter-> next;
    //First Name
    cout << "Enter the first name:" << endl;
    cin >> iter->firstName;
    cin.ignore(1000, '\n');
    //Last Name
    cout << "Enter " << iter->firstName << "'s last name" << endl;
    cin >> iter->lastName;
    cin.ignore(1000, '\n');
    //Phone  Number
    cout << "Enter " << iter->firstName << "'s phone number" << endl;
    cin >> iter->phoneNumber;
    cin.ignore(1000, '\n');
    //Address
    cout << "Enter " << iter->firstName << "'s address" << endl;
    cin >> iter->address;
    cin.ignore(1000, '\n');
}
void updateContact(struct Contact* &head) {
    //Update existing contact
    int choice;
    cout << "Choose a contact to edit (enter a number)" << endl; 
    printAllContacts(head);
    cin >> choice;
    int numContacts = getNumContacts(head);
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
    struct Contact* chosenCont = getNth(head, choice-1); //Chosen contact
    bool contUpdate = true; //Continue updateing
    while (contUpdate) {
        printContact(chosenCont);
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
                cin >> chosenCont->firstName;
                cin.ignore(1000, '\n');
                break;
            case 2:
                //Update last name
                cout << "Enter the new last name: " << endl;
                cin >> chosenCont->lastName;
                cin.ignore(1000, '\n');
                break;
            case 3:
                //Update phone number
                cout << "Enter the new phone number: " << endl;
                cin >> chosenCont->phoneNumber;
                cin.ignore(1000, '\n');
                break;
            case 4:
                //Update address
                cout << "Enter the new address: " << endl;
                cin >> chosenCont->address;
                cin.ignore(1000, '\n');
                break;
            default:
                contUpdate = false;
        }
    }
}
void delContact(struct Contact* &head) {
    //This should probebly work by index
    struct Contact* temp;
    int delChoice;
    cout << "Choose a contact to delete from this list (enter a number)" << endl;
    printAllContacts(head);
    cin >> delChoice;
    int numContacts = getNumContacts(head);
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
        temp = head->next;
        delete head;
        head = temp;
    }
    else {
        struct Contact* toDel = getNth(head, delChoice);
        getNth(head, delChoice-1)->next = toDel->next;
        delete toDel;
    }
}
void listContacts(struct Contact* &head) {
    //Needs to sort first
    sortBook(head);
    //Then, print everything
    printAllContacts(head);
    //Now we ask user if they want to view one of them
    int userIn;
    int numContacts = getNumContacts(head);
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
        printContact(getNth(head, userIn-1));
    }
}
void findContact(struct Contact* &head) {
    string toFindFirst, toFindLast; //Name
    cout << "Enter the first name" << endl;
    cin >> toFindFirst;
    cin.ignore(1000, '\n');
    cout << "Enter the last name" << endl;
    cin >> toFindLast;
    cin.ignore(1000, '\n');
    struct Contact* iter = head;
    bool found = false;
    while(iter != nullptr && !found) {
        if (iter->firstName == toFindFirst && iter->lastName == toFindLast) {
            //Found the contact
            printContact(iter);
            found = true;
        }
        iter = iter->next;
    }
    //If we didn't find it, tell the user
    if (!found) {
        cout << "Error: that contact does not exist" << endl;
    }
}
bool mainMenu(struct Contact* &head) {
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
            addContact(head);
            break;
        case 2:
            updateContact(head);
            break;
        case 3:
            delContact(head);
            break;
        case 4:
            listContacts(head);
            break;
        case 5:
            findContact(head);
            break;
        case 6:
            return false;
    }
    return true; //If we don't quit, show menu again
}
int main() {
    struct Contact* head = new Contact;
    head->firstName = "Test";
    head->lastName = "Person";
    head->phoneNumber = "(000)000-0000";
    head->address = "50 Frida Kahlo Way, San Francisco, CA 94112";
    bool cont = true; //Should the program continue
    cout << "This is your contact book" << endl;
    do {
        cont = mainMenu(head);
    } while(cont);
    return 0;
}
