#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "vector"

#pragma once
using namespace std;

template<typename T>
struct Node {
    T *currentNode;
    Node<T> *nextNode;
    int weight;
};


template<typename T>
class NodeLinkedList {
public:

    int length = 0;
    Node<T> *linkedList
            = new Node<T>{.currentNode = nullptr, .nextNode = nullptr};


    void add(T *node, int weight) {
        auto *_node = new Node<T>();
        _node->currentNode = node;
        _node->weight = weight;
        _node->nextNode = linkedList;
        linkedList = _node;
        length++;
    }


};

struct Vertex {
    int value = -1;
    int color = -1;
    int d = INT32_MAX;
    int f = 0;
    Vertex *pi = nullptr;

    Vertex() {

    }

    Vertex(int value, int status) {
        this->value = value;
        this->color = status;
    }
};

struct Edge {

    Vertex *u = nullptr;
    Vertex *v = nullptr;
    int weight;

    Edge(Vertex *u, Vertex *v, int weight) {
        this->u = u;
        this->v = v;
        this->weight = weight;
    }
};

class UndirectedGraphWithWeights {
public:
    int n = 0;
    int m = 0;
    int **adjacencyMatrix = nullptr;
    NodeLinkedList<Vertex> *adjacencyList = nullptr;
    Vertex *vertices = nullptr;
    vector<Edge> edges;

    UndirectedGraphWithWeights() {
        cout << "Enter the number of Vertices: ";
        cin >> n;

        cout << "Enter the number of Edges: ";
        cin >> m;
        createGraph(n, m);
    }

    explicit UndirectedGraphWithWeights(bool createEmpty) {

    }

    explicit UndirectedGraphWithWeights(const string &filename) {
        std::ifstream f(filename);
        string line;


        std::getline(f, line);
        std::istringstream iss(line);
        iss >> this->n >> this->m;
        adjacencyMatrix = new int *[n];

        for (int i = 0; i < n; i++) {
            adjacencyMatrix[i] = new int[n];
        }
        vertices = new Vertex[n];
        for (int i = 0; i < n; i++) {
            vertices[i] = *new Vertex(i, 0);
        }
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) adjacencyMatrix[i][j] = INT32_MAX;

//        cout << "Edges Detected: " << endl;
        int tm = m;
        while (tm--) {

            std::getline(f, line);
            std::istringstream iss(line);
            int startnode, endnode, weight;
            iss >> startnode >> endnode >> weight;
//           cout << startnode << "->" << endnode << endl;
            adjacencyMatrix[startnode][endnode] = weight;
            adjacencyMatrix[endnode][startnode] = weight;

        }


    }

    UndirectedGraphWithWeights(int n, int m) {
        this->n = n;
        this->m = m;
        createGraph(n, m);
    }

    void createGraph(int n, int m) {
        adjacencyMatrix = new int *[n];

        for (int i = 0; i < n; i++) {
            adjacencyMatrix[i] = new int[n];
        }
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) adjacencyMatrix[i][j] = 0;
        vertices = new Vertex[n];
        for (int i = 0; i < n; i++) {
            vertices[i] = *new Vertex(i, 0);
        }
        int tm = m;
        cout << "Enter the edges: ";
        while (tm--) {


            int startnode, endnode, weight;
            cin >> startnode >> endnode >> weight;
//            cout << startnode << " -> " << endnode << endl;

            adjacencyMatrix[startnode][endnode] = weight;
            adjacencyMatrix[endnode][startnode] = weight;

        }


    }

    void printAdjacencyMatrix() {
        printf("|  ");
        for (int i = 0; i < n; i++) {
            printf("%d_", i);
        }

        printf("\n");


        for (int i = 0; i < n; i++) {
            printf("%d| ", i);
            for (int j = 0; j < n; j++) {
                printf("%d ", adjacencyMatrix[i][j] == INT32_MAX ? 0 : adjacencyMatrix[i][j]);
            }

            printf("\n");
        }
    }

    void createAdjacencyListFromMatrix() {
        adjacencyList = new NodeLinkedList<Vertex>[n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (adjacencyMatrix[i][j] != INT32_MAX) {
                    adjacencyList[i].add(&vertices[j], adjacencyMatrix[i][j]);
                }
            }
        }

    }

    void printAdjacencyList() {
        for (int i = 0; i < n; i++) {
            printf("%d: ", i);
            NodeLinkedList<Vertex> linkedList = adjacencyList[i];
            Node<Vertex> *curr = linkedList.linkedList;
            while (curr->currentNode != nullptr) {
                printf("%d->", curr->currentNode->value);
                curr = curr->nextNode;
            }
            printf("\n");


        }


    }

    void createEdges() {
        for (int i = 0; i < this->n; i++) {
            for (int j = 0; j < this->n; j++) {
                if (adjacencyMatrix[i][j] != INT32_MAX) {
                    edges.push_back(Edge(&vertices[i], &vertices[j], adjacencyMatrix[i][j]));
                }
            }
        }
    }

    void printEdges() {
        for (auto edge: edges) {
            printf("%d -> %d (%d)\n", edge.u->value, edge.v->value, edge.weight);
        }
    }


    static UndirectedGraphWithWeights *Inverse(UndirectedGraphWithWeights *G);
};

UndirectedGraphWithWeights *UndirectedGraphWithWeights::Inverse(UndirectedGraphWithWeights *argG) {
    UndirectedGraphWithWeights *G = new UndirectedGraphWithWeights(true);
    G->n = argG->n;
    G->m = argG->m;
    G->adjacencyMatrix = new int *[G->n];

    G->vertices = argG->vertices;

    for (int i = 0; i < G->n; i++) {
        G->adjacencyMatrix[i] = new int[G->n];
    }


    for (int i = 0; i < argG->n; i++) {
        for (int j = 0; j < argG->n; j++) {
            G->adjacencyMatrix[i][j] = argG->adjacencyMatrix[j][i];
        }
    }
    return G;
}

