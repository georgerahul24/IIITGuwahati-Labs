#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#pragma once
using namespace std;

template<typename T>
struct Node {
    T *currentNode;
    Node<T> *nextNode;
};


template<typename T>
class NodeLinkedList {
public:

    int length = 0;
    Node<T> *linkedList
            = new Node<T>{.currentNode = nullptr, .nextNode = nullptr};


    void add(T *node) {
        auto *_node = new Node<T>();
        _node->currentNode = node;
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
};

class DirectedGraph {
public:
    int n = 0;
    int m = 0;
    int **adjacencyMatrix = nullptr;
    NodeLinkedList<Vertex> *adjacencyList = nullptr;
    Vertex *vertices = nullptr;

    DirectedGraph() {
        cout << "Enter the number of Vertices: ";
        cin >> n;

        cout << "Enter the number of Edges: ";
        cin >> m;
        createGraph(n, m);
    }

    explicit DirectedGraph(bool createEmpty) {

    }

    explicit DirectedGraph(const string &filename) {
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
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) adjacencyMatrix[i][j] = 0;

//        cout << "Edges Detected: " << endl;
        int tm = m;
        while (tm--) {

            std::getline(f, line);
            std::istringstream iss(line);
            int startnode, endnode;
            iss >> startnode >> endnode;
//            cout << startnode << "->" << endnode << endl;
            adjacencyMatrix[startnode][endnode] = 1;

        }


    }

    DirectedGraph(int n, int m) {
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


            int startnode, endnode;
            cin >> startnode >> endnode;
//            cout << startnode << " -> " << endnode << endl;

            adjacencyMatrix[startnode][endnode] = 1;

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
                printf("%d ", adjacencyMatrix[i][j]);
            }

            printf("\n");
        }
    }

    void createAdjacencyListFromMatrix() {
        adjacencyList = new NodeLinkedList<Vertex>[n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (adjacencyMatrix[i][j] == 1) {
                    adjacencyList[i].add(&vertices[j]);
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


    static DirectedGraph *Inverse(DirectedGraph *G);
};

DirectedGraph *DirectedGraph::Inverse(DirectedGraph *argG) {
    DirectedGraph *G = new DirectedGraph(true);
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

