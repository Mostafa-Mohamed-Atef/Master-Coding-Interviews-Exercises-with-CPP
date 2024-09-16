#include <iostream>
using namespace std;

class Node {
    public:
    int value;
    Node* next;

    Node(int val) {
        value = val;
        next = NULL;
    }
};
class Queue {
    public:
    Node* first = NULL;
    Node* last = first;
    int len = 0;

    Queue(int newValue) {
        first = new Node(newValue);
        first->next = last;
        len++;
    }

    //peek
    void peek() {
        cout<<first->value<<endl;
    }

    //last
    void last_item() {
        cout<<last->value<<endl;
    }

    //enqueue 
    void enqueue(int newValue) {
        Node* newLast = new Node(newValue);
        // Node* temp = last;
        if(first->next == NULL){
            first->next = newLast;
        } else {
            last->next = newLast;
        }
        last = newLast;
        len++;

    }
    //dequeue
    void dequeue() {
        Node* temp = first;
        first = temp->next;
        delete temp;
        len--;
    }

    void printQueue() {
        Node* temp = first;
        while (temp != NULL)
        {
            cout<<temp->value<<" ";
            temp = temp->next;
        }
        cout<<endl;
        cout<<"Length = "<<len<<endl;
        
    }
};

int main() {
    Queue q(1);

    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    // q.dequeue();
    q.peek();
    q.last_item();
    q.printQueue();
    q.dequeue();
    q.peek();
    q.printQueue();
}