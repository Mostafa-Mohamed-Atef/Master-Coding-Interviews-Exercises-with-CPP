//BFS => using binary search tree 
void breadthFirstSearch() {
    if (root == nullptr) return;
    vector<int> list; //the main arr 
    vector<Node*> queue; // to keep track the level for accessing the children 
    queue.push_back(root);
    while (queue.size() > 0) {
        Node* temp = queue.front(); 
        queue.erase(queue.begin());
        list.push_back(temp->data);
        if(temp->left != nullptr) {
            queue.push_back(temp->left);
        }
        if (temp->right != nullptr) {
            queue.push_back(temp->right);
        }
    }
    for (int i : list) {
        cout<<i<<endl;
    }
}