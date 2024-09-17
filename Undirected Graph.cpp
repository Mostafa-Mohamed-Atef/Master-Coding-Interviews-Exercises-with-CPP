#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class Node {
    public:
    int data;
    list<int> edges;  // List to store edges for the current vertex
    Node(int value) {
        data = value;
    }
};

class UndirectedGraph {
    public:
    unordered_map<int, Node*> vertices; // Adjacency list using a hash map

    // Add a new vertex
    void addVertex(int value) {
        if (vertices.find(value) == vertices.end()) {
            Node* newVertex = new Node(value);
            vertices[value] = newVertex;
            cout << "Vertex " << value << " added.\n";
        } else {
            cout << "Vertex " << value << " already exists.\n";
        }
    }

    // Add an undirected edge between two vertices
    void addEdge(int from, int to) {
        if (vertices.find(from) != vertices.end() && vertices.find(to) != vertices.end()) {
            vertices[from]->edges.push_back(to); // Add an edge from 'from' to 'to'
            vertices[to]->edges.push_back(from); // Since it's undirected, add an edge from 'to' to 'from'
            cout << "Edge between " << from << " and " << to << " added.\n";
        } else {
            cout << "One or both vertices not found.\n";
        }
    }

    // Display the graph
    void displayGraph() {
        for (auto vertexPair : vertices) {
            Node* vertex = vertexPair.second;
            cout << "Vertex " << vertex->data << ": ";
            for (int edge : vertex->edges) {
                cout << edge << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    UndirectedGraph g;

    g.addVertex(1);
    g.addVertex(2);
    g.addVertex(3);
    
    g.addEdge(1, 2);
    g.addEdge(1, 3);

    g.displayGraph();

    return 0;
}
