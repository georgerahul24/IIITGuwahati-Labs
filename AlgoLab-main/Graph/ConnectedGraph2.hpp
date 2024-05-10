#include "DirectedGraphWithoutWeights.hpp"
#include "vector"

class ConnectedGraph2 {
public:


    explicit ConnectedGraph2(const string &filename, bool *argConnected) {
        DirectedGraph *G, *invG;
        G = new DirectedGraph(filename);
        G->createAdjacencyListFromMatrix();
        invG = DirectedGraph::Inverse(G);
        G->printAdjacencyMatrix();
        invG->printAdjacencyMatrix();
        invG->createAdjacencyListFromMatrix();
        int dfsG = DFS(0, G);
        int dfsinvG = DFS(0, invG);
        *argConnected = (dfsG == dfsinvG) && (dfsG == G->n);


    }

    int DFS(int i, DirectedGraph *G) {

        vector<Vertex> *vec = new vector<Vertex>();

        for (int i = 0; i < G->n; i++) {
            G->vertices[i].color = 0;
            G->vertices[i].d = INFINITY;
            G->vertices[i].f = 0;
        }

        DFS_VISIT(&G->vertices[i], vec, G);
        return vec->size();

    }


    void DFS_VISIT(Vertex *u, vector<Vertex> *vec, DirectedGraph *G) {

        u->color = 1;
        Node<Vertex> *curr = G->adjacencyList[u->value].linkedList;
        while (curr->currentNode != nullptr) {
            Vertex *v = curr->currentNode;
            if (v->color == 0) {
                v->pi = u;
                DFS_VISIT(v, vec, G);
            }
            curr = curr->nextNode;
        }
        u->color = 2;
        vec->push_back(*u);

    }
};


