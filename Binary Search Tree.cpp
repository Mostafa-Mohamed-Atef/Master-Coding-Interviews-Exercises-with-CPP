#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* right;
    Node* left;
    Node(int val) {
        data = val;
        right = nullptr;
        left = nullptr;
    }
};

class BinarySearchTree {
    public:
    Node* root;
    BinarySearchTree() {
        root = nullptr;
    }

    //insert 
    void insert(int value) {
        Node* newNode = new Node(value);  // Create a new node with the value
        if (root == nullptr) {  // Check if the root is null (empty tree)
            root = newNode;
        } else {
            Node* temp = root;
            while (true) {
                if (newNode->data < temp->data) {  // Go to the left subtree
                    if (temp->left == nullptr) {  // If left is null, insert new node here
                        temp->left = newNode;
                        return;
                    }
                    temp = temp->left;  // Move left
                } else {  // Go to the right subtree
                    if (temp->right == nullptr) {  // If right is null, insert new node here
                        temp->right = newNode;
                        return;
                    }
                    temp = temp->right;  // Move right
                }
            }
        }
    }

    //lookup
    void lookup(int value) {
        if(root == nullptr) {
            cout<<"Tree is Empty \n";
            return;
        } else {
            Node* temp = root;
            while(temp != nullptr) {
                if (value < temp->data ) {
                    temp = temp->left;
                } 
                else if (value > temp->data) {
                    temp = temp->right;
                } else if (value == temp->data) {
                    cout<<"Exists \n";
                    return;
                }
            cout<<"Doesn't exist \n";
            return;
            }
        }
    }

    //remove
    void remove(int value) {
        if (root == nullptr) {
            cout<< "Tree is Empty \n";
            return;
        } else {   
            Node* temp = root;
            Node* parentNode = nullptr;
            while(temp != nullptr) {
                if (value < temp->data ) {
                    temp = temp->left;
                } 
                else if (value > temp->data) {
                    temp = temp->right;
                } else if (value == temp->data) {
                    if (temp->right == nullptr){
                        if (parentNode == nullptr) {
                            root = temp->left;
                        } else {
                            if(temp->data < parentNode->data) {
                                parentNode->left = temp->left;
                            } else if (temp->data > parentNode->data) {
                                parentNode->right = temp->left;
                            }
                        }
                    }
                }
            }
        }
    }

    //print
    void printTreeHelper(Node* root, int space = 0, int levelSpacing = 4) {
        if (root == nullptr)
            return;

        space += levelSpacing;

        // Print right subtree first
        printTreeHelper(root->right, space);

        cout << endl;
        for (int i = levelSpacing; i < space; i++)
            cout << " ";
        cout << root->data << endl;

        // Print left subtree
        printTreeHelper(root->left, space);
    }

    void printTree() {
        printTreeHelper(root);
    }

};

int main() {
    BinarySearchTree tree;
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    tree.insert(1);
    tree.insert(2);
    tree.printTree();
    cout<<endl;
    tree.lookup(5);
    tree.lookup(8);


}