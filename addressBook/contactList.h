#ifndef CONTACTLIST_H
#define CONTACTLIST_H

#include <iostream>
#include <fstream>
#include <list>
#include <iterator>
#include "contact.h"
using namespace std;

class ContactList {
    private:
        list <Contact*> contacts;
    public:
        //ContactList();
        ~ContactList();
        //Methods used by other methods in this class
        Contact* getNth(const int &index) const;
        void printList() const; 
        
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
