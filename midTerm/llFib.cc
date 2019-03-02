#include <iostream>
using namespace std;
//Implementing a linked list here
struct node {
    int data;
    struct node* next;
};

int main() {
    //First initialize head and initial values
    struct node* head = new node;
    head->data = 1;
    head->next = new node;
    head->next->data = 2;
    //Now fill linked list up to where the fib value is 1000
    struct node* iter = head; //Iter should be whatever we need to read first
    while (iter->data + iter->next->data <= 1000) {
        iter->next->next = new node;
        iter->next->next->data = iter->data + iter->next->data;
        iter = iter->next;
    }
    //Now to sum up numbers
    int sum = 0; //For adding numbers up
    iter = head; //Put iter back to head
    while (iter->next != NULL) {
        if (!(iter->data % 2)) {
            sum += iter->data;
        }
        iter = iter->next;
    }
    cout << "The sum of even values is " << sum << endl;
    return 0;
}
