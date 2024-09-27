//BFS Recursive
void breadthFirstSearchRecursive(vector<int> list, vector<Node*> queue) {
    if (root == nullptr) return;
    Node* temp = queue.front(); 
    queue.erase(queue.begin());
    list.push_back(temp->data);
    if(temp->left != nullptr) {
        queue.push_back(temp->left);
    }
    if (temp->right != nullptr) {
        queue.push_back(temp->right);
    }
    for (int i : list) {
    cout<<i<<endl;
    }
    return breadthFirstSearchRecursive(list, queue);
}
int main() {
    vector<int> list;
    vector<Node*> queue;
    tree.breadthFirstSearchRecursive(list, queue);
}