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
    int weight;

    Edge(Vertex *u, Vertex *v, int weight) {
        this->u = u;
        this->v = v;
        this->weight = weight;
    }
};

struct adjacencyListEdge {
    Vertex *vertex;
    int weight;

    adjacencyListEdge(Vertex *vertex, int weight) {
        this->vertex = vertex;
        this->weight = weight;
    }

};


class DirectedGraphWithWeights {
public:
    int n = 0;
    int m = 0;
    int **adjacencyMatrix = nullptr;
    vector<vector<adjacencyListEdge>> *adjacencyList = nullptr;
    vector<Vertex> vertices;
    vector<Edge> edges;

    DirectedGraphWithWeights() {
        cout << "Enter the number of Vertices: ";
        cin >> n;

        cout << "Enter the number of Edges: ";
        cin >> m;
        createGraph(n, m);
    }

    DirectedGraphWithWeights(bool createEmpty) {

    }

    DirectedGraphWithWeights(const string &filename) {
        std::ifstream f(filename);
        string line;


        std::getline(f, line);
        std::istringstream iss(line);
        iss >> this->n >> this->m;
        adjacencyMatrix = new int *[n];

        for (int i = 0; i < n; i++) {
            adjacencyMatrix[i] = new int[n];
        }
        for (int i = 0; i < n; i++) {
            vertices.emplace_back(i, 0);
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

        }


    }

    DirectedGraphWithWeights(int n, int m) {
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
        for (int i = 0; i < n; i++) {
            vertices.emplace_back(i, 0);
        }
        int tm = m;
        cout << "Enter the edges: ";
        while (tm--) {


            int startnode, endnode, weight;
            cin >> startnode >> endnode >> weight;
//            cout << startnode << " -> " << endnode << endl;

            adjacencyMatrix[startnode][endnode] = weight;

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
        adjacencyList = new vector<vector<adjacencyListEdge>>;
        for (int i = 0; i < n; i++) {
            auto vec = new vector<adjacencyListEdge>;
            for (int j = 0; j < n; j++) {

                if (adjacencyMatrix[i][j] != INT32_MAX) {
                    vec->push_back(adjacencyListEdge(&vertices.at(j), adjacencyMatrix[i][j]));
                }

            }
            adjacencyList->push_back(*vec);
        }

    }

    void printAdjacencyList() {
        for (int i = 0; i < n; i++) {
            printf("%d: ", i);
            vector<adjacencyListEdge> linkedList = adjacencyList->at(i);
            for (auto ver: linkedList) {
                printf("%d -> ", ver.vertex->value);
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


    static DirectedGraphWithWeights *Inverse(DirectedGraphWithWeights *G);
};

DirectedGraphWithWeights *DirectedGraphWithWeights::Inverse(DirectedGraphWithWeights *argG) {
    DirectedGraphWithWeights *G = new DirectedGraphWithWeights(true);
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

