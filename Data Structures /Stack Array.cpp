#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Stack {
    public:
    vector<int> stack = {};
    int len = 0;

    Stack(int newVal) {
        stack.push_back(newVal);
        len++;
    }

    //peek
    void peek() {
        cout<< stack.back()<<endl;
    }

    //push
    void push(int value) {
        stack.push_back(value);
        len++;
    }

    //pop
    void pop() {
        stack.pop_back();
        len--;

    }
    void printStack() {
        for(int i=stack.size()-1;i>=0; i--) {
            cout << stack[i] << " ";
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
/*
1 
Length = 1
2
3
3 2 1 
Length = 3
[1] + Done
*/