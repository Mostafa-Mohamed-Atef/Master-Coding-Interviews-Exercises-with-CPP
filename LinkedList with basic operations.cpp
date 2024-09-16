#include <iostream>
using namespace std;

// Creating a node class
class Node {
public:
    int value;
    Node* next;
    

    // Constructor to initialize the node
    Node(int val) {
        value = val;
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;
    Node* tail = head;
    int length = 0;

    // Constructor
    LinkedList(int headValue) {
        head = new Node(headValue);
        length ++;
    }

    // Append method to add a node to the end
    void append(int value) {
        Node* newNode = new Node(value);
        if(head->next == NULL){
            head->next = newNode;
        } else {
            tail->next = newNode;
        }
            tail = newNode;
            length++;
    }
    
    //Preappend
    void preappend(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        length++;
    }
    
    //insert
    void insert(int index, int value) {
        Node* newNode = new Node(value);
        Node* temp = head;
        int i = 0;
        if(index == 0) {
            return preappend(value);
        }else {
            while(i!=index) {
                temp = temp->next;
                i++;
            }
                
            newNode->next = temp->next;
            temp->next = newNode;
            length++;
        }
    }
    
    //remove
    void remove(int index) {
        Node* temp = head;
        Node* pastNode;
        int i = 0;
        if(index == 0) {
            head = temp->next;
            delete temp;
            length--;
            return;
        }else {
            while(i!=index) {
                pastNode = temp;
                temp = temp->next;
                i++;
            }
                
            pastNode->next = temp->next;
            delete temp;
            length--;
        }
    }

    // Print 
    void printList() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
        cout<<length<<endl;
    }
};

int main() {
    // Create a linked list with head value 1
    LinkedList list(1);

    // Append more values to the list
    list.append(2);
    list.append(3);
    list.append(4);
    list.preappend(0);
    list.insert(0,6);
    list.insert(5,10);

    // Print the linked list values
    list.printList();
    list.remove(3);
    
    list.printList();


    return 0;
}
