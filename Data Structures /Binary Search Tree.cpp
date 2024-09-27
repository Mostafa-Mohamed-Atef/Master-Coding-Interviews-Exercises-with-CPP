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
            }
            cout<<"Doesn't exist \n";
            return;
        }
    }

    //remove
    void remove(int value) {
        if (root == nullptr) {
            cout<< "Tree is Empty \n";
            return;
        } else {   
            Node* temp = root;
            Node* parentNode = nullptr; //we need a reference to the parent node 
            while(temp != nullptr) {
                if (value < temp->data ) {
                    parentNode = temp;
                    temp = temp->left;
                } 
                else if (value > temp->data) {
                    parentNode = temp;
                    temp = temp->right;
                } else if (value == temp->data) {
                    //Case 1: No Right Child
                    if (temp->right == nullptr){
                        if (parentNode == nullptr) {
                            root = temp->left;
                        } else {
                            //if parent > current value, make current value left child of parent
                            if(temp->data < parentNode->data) {
                                parentNode->left = temp->left;
                                //if parent < current value, make left child a right child of parent
                            } else if (temp->data > parentNode->data) {
                                parentNode->right = temp->left;
                            }
                        }
                        //Case 2: Right child which doesn't have a left child 
                    } else if (temp->right->left == nullptr) {
                        temp->right->left = temp->left;
                        if (parentNode == nullptr) {
                            root = temp->right;
                        } else {
                            //if parent > current, make right child of the left the parent 
                            if (temp->data < parentNode->data) {
                                parentNode->left = temp->right;
                            //if parent < current, make right child a right child of the parent 
                            } else if (temp->data > parentNode->data) {
                                parentNode->right = temp->right;
                            }
                        }
                    // Case 3: Right child that has a left child 
                    } else {
                        //find the right child that has a left child 
                        Node* leftMost = temp->right->left;
                        Node* leftMostParent = temp->right;
                        while (leftMost->left != nullptr) {
                            leftMostParent = leftMost;
                            leftMost = leftMost->left;
                        }

                        //Parent's left subtree is now leftmost's right subtree
                        leftMostParent->left = leftMost->right;
                        leftMost->left = temp->left;
                        leftMost->right = temp->right;
                        if (parentNode == nullptr) {
                            root = leftMost;
                        } else {
                            if (temp->data < parentNode->data) {
                                parentNode->left = leftMost;
                            } else if (temp->data > parentNode->data) {
                                parentNode->right = leftMost;
                            }
                        }
                    }
                    return;
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
    tree.insert(6);
    tree.insert(5);
    tree.insert(1);
    tree.insert(2);
    tree.insert(8);
    tree.insert(7);

    // tree.printTree();
    cout<<endl;
    tree.lookup(5);
    tree.lookup(8);
    tree.remove(3);
    tree.remove(2);
    tree.remove(6);

    tree.printTree();





}