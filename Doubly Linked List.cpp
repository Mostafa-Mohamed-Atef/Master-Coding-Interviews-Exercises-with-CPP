#include <iostream>
using namespace std;

// Creating a node class
class Node {
public:
    int value;
    Node* next;
    Node* previous;
    

    // Constructor to initialize the node
    Node(int val) {
        value = val;
        next = NULL;
        previous = NULL;
    }
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail = head;
    int length = 0;

    // Constructor
    DoublyLinkedList(int headValue) {
        head = new Node(headValue);
        length ++;
    }

    // Append method to add a node to the end
    void append(int value) {
        Node* newNode = new Node(value);
        if(head->next == NULL){
            head->next = newNode;
            newNode->previous = head;
        } else {
            tail->next = newNode;
            newNode->previous = tail;
        }
            tail = newNode;
            length++;
    }
    
    //Preappend
    void preappend(int value) {
        Node* newNode = new Node(value);
        head->previous = newNode;
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
            temp->previous = newNode;
            temp->next = newNode;
            newNode->previous = temp;
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
            temp->next->previous = pastNode;
            delete temp;
            length--;
        }
    }
    
    //reverse
    void reverse() {
        Node* first = head;
        Node* second = first->next;
        tail = head;

        while (second != NULL) {
            Node* temp = second->next;
            second->next = first;
            first = second;
            second = temp;
        }
        head->next = NULL;
        tail = head;
        head = first;
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
    DoublyLinkedList list(1);

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
    list.reverse();
    list.printList();

    return 0;
}
