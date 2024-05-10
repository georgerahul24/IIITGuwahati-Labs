#include <iostream>

using namespace std;
typedef struct Node {
    int visited;
    int number;
} Node;


typedef struct Edge {
    Node *u;
    Node *v;
};


class Graph {
public:
    Node *nodes = nullptr;
    Edge *edges = nullptr;

    Graph() {

    }

    int **getAdjacencyMatrix() {
        printf("Enter the number of nodes(n): ");
        int n;
        cin >> n;
        printf("Enter the Adjacency Matrix: \n");


    }

    Node **getAdjacencyList() {

    }

    Node **adjacencyMatrixToListUndirected() {

    }

    int **adjacencyListToMatrixUndirected() {

    }

    Node **adjacencyMatrixToListDirected() {

    }

    int **adjacencyListToMatrixDirected() {

    }


};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
