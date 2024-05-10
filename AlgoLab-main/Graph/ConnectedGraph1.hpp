#include "DirectedGraphWithoutWeights.hpp"
#include "queue"


using namespace std;

class ConnectedGraph1 {
public:
    DirectedGraph *G = nullptr;


    explicit ConnectedGraph1(const string &filename,bool * argConnected) {
        G = new DirectedGraph(filename);
        G->createAdjacencyListFromMatrix();

        bool connected = true;
        for (int i = 0; i < G->n; i++) {
            connected *= G->n == DFS(i);
        }

        *argConnected = connected;

    }


    int DFS(int i) {

        vector<Vertex> *vec = new vector<Vertex>();

        for (int i = 0; i < G->n; i++) {
            G->vertices[i].color = 0;
            G->vertices[i].d = INFINITY;
            G->vertices[i].f = 0;
        }

        DFS_VISIT(&G->vertices[i], vec);
        return vec->size();

    }


    void DFS_VISIT(Vertex *u, vector<Vertex> *vec) {

        u->color = 1;
        Node<Vertex> *curr = G->adjacencyList[u->value].linkedList;
        while (curr->currentNode != nullptr) {
            Vertex *v = curr->currentNode;
            if (v->color == 0) {
                v->pi = u;
                DFS_VISIT(v, vec);
            }
            curr = curr->nextNode;
        }
        u->color = 2;
        vec->push_back(*u);

    }

};