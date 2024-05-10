#include "DirectedGraphWithoutWeights.hpp"
#include "queue"
#include "vector"
using namespace std;

class TopologicalSorting {
public:
    DirectedGraph *G = nullptr;
    int time = 0;

    vector<Vertex> topologicalSortedVertices;

    explicit TopologicalSorting(const string &filename) {

        G = new DirectedGraph(filename);
        G->createAdjacencyListFromMatrix();
        printf("\nTopological Sorting\n");

        for (int i = 0; i < G->n; i++) {
            G->vertices[i].color = 0;
            G->vertices[i].d = INFINITY;
            G->vertices[i].f = 0;
        }


        for (int i = 0; i < G->n; i++) {
            if (G->vertices[i].color == 0) {
                DFS_VISIT(&G->vertices[i]);
            }
        }
        printVector();

    }

    void DFS_VISIT(Vertex *u) {
        u->d = ++time;
        u->color = 1;

        Node<Vertex> *curr = G->adjacencyList[u->value].linkedList;

        while (curr->currentNode != nullptr) {
            Vertex *v = curr->currentNode;
            if (v->color == 0) {
                v->pi = u;
                DFS_VISIT(v);
            }
            curr = curr->nextNode;
        }
        u->color = 2;
        time++;
        u->f = time;
        topologicalSortedVertices.push_back(*u);

    }

    void printVector(){
        std::reverse(topologicalSortedVertices.begin(), topologicalSortedVertices.end());
        for(auto vertex:topologicalSortedVertices){
            printf("%d ",vertex.value);
        }
    }
};