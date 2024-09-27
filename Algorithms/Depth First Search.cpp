//Traverse inorder
void DFS() { //O(height of the tree)
    if (root == nullptr) return;
    vector<int> list;
    Node* temp = root;
    inorder(temp, list);
    
    for (int i : list) {
        cout<<i<<" ";
    }
    list.clear();
    preorder(temp, list);
    cout<<endl;
    for (int i : list) {
        cout<<i<<" ";
    }
    list.clear();
    postorder(temp, list);
    cout<<endl;
    for (int i : list) {
        cout<<i<<" ";
    }
}
void inorder(Node* temp, vector<int>& list) {
    if (temp->left != nullptr ) {
        inorder(temp->left, list);
    }
    list.push_back(temp->data);
    if (temp->right != nullptr) {
        inorder(temp->right, list);
    }
}
void preorder(Node* temp, vector<int>& list) {
    list.push_back(temp->data);
    if(temp->left != nullptr) {
        preorder(temp->left, list);
    }
    if(temp->right != nullptr) {
        preorder(temp->right, list);
    }
}
void postorder(Node* temp, vector<int>& list) {
    if (temp->left != nullptr) {
        postorder(temp->left, list);
    }
    if (temp->right != nullptr) {
        postorder(temp->right, list);
    }
    list.push_back(temp->data);
}