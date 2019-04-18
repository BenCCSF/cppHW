#ifndef CONTACTLIST_H
#define CONTACTLIST_H

#include <iostream>
#include <fstream>
#include "contact.h"
using namespace std;

class ContactList {
    private:
        Contact *head;
        int numContacts;
    public:
        ContactList(); //Initializes list with one element as head (Full of null values)

        //Methods used by other methods in this class
        Contact* getNth(const int &index) const;
        void printList() const; 
        void sortList();
        
        //Methods called by main menu
        void addContact();
        void updateContact();
        void delContact();
        void listContacts();
        void findContact();
        void saveList();
        void loadList(); 
};

#endif
