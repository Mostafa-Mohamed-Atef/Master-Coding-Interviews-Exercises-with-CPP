#include <iostream>
#include <string>
#include <map>
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
class Stack {
    public:
    Node* top;
    Node* bottom;
    int len = 0;  

    Stack(int newVal) {
        top = new Node(newVal);
        len++;
    }

    //peek
    void peek() {
        cout << top->value<<endl;
    }
    
    //push
    void push(int value) {
        Node* newTop = new Node(value);
        newTop->next = top;
        top = newTop;
        len++;
    }

    //pop
    void pop() {
        Node* temp = top;
        top = temp->next;
        delete temp;
        len--;

    }

    void printStack() {
        Node* temp = top;
        while(temp != NULL) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout<<endl;
        cout <<"Length = " << len<<endl;
    }
};

int main() {
    Stack stack(1);

    stack.printStack();
    stack.push(2);
    stack.push(3);
    stack.push(2);
    stack.peek();
    stack.pop();
    stack.peek();
    stack.printStack();
}