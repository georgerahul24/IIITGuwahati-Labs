#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "vector"

#pragma once
using namespace std;


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

    Edge(Vertex *u, Vertex* v){
        this->u=u;
        this->v=v;
    }
};

class DirectedGraph {
public:
    int n = 0;
    int m = 0;
    int **adjacencyMatrix = nullptr;
    vector<vector<Vertex *> *> *adjacencyList = nullptr;
    Vertex *vertices = nullptr;

    vector<Edge *> edges;

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
            edges.push_back(new Edge(&vertices[startnode], &vertices[endnode]));

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
        adjacencyList = new vector<vector<Vertex *> *>();

        for (int i = 0; i < n; i++) {
            adjacencyList->push_back(new vector<Vertex *>());
            for (int j = 0; j < n; j++) {
                if (adjacencyMatrix[i][j] == 1) {
                    adjacencyList->at(i)->push_back(&vertices[j]);
                }
            }
        }


    }

    void printAdjacencyList() {
        for (int i = 0; i < n; i++) {
            printf("%d: ", i);
            vector<Vertex *> *linkedList = adjacencyList->at(i);
            for (auto ver: *linkedList) {
                printf("%d->", ver->value);
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
    G->vertices = new Vertex[G->n];

    for (int i = 0; i < G->n; i++) {
        Vertex v = argG->vertices[i];
        Vertex *_v = new Vertex();
        _v->color = 0;
        _v->d = 0;
        _v->pi = NULL;
        _v->f = 0;
        _v->value = v.value;
        G->vertices[i] = *_v;

    }
    for (int i = 0; i < G->n; i++) {
        G->vertices->color = 0;
        G->vertices->d = 0;
        G->vertices->pi = NULL;
        G->vertices->f = 0;
    }


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

