#include "DirectedGraphWithoutWeights.hpp"
#include "queue"

using namespace std;

class BFS {
public:
    explicit BFS(const string &filename) {

        DirectedGraph G(filename);
        G.createAdjacencyListFromMatrix();
        printf("BFS\n");

        for (int i = 0; i < G.n; i++) {
            G.vertices[i].color = 0;
            G.vertices[i].d = INFINITY;
            G.vertices[i].f = 0;
        }

        G.vertices[0].color = 1;
        G.vertices[0].d = 0;
        G.vertices[0].f = 0;

        queue<Vertex *> Q;
        Q.push(&G.vertices[0]);

        while (!Q.empty()) {
            Vertex *u = Q.front();
            Q.pop();

            Node<Vertex> *curr = G.adjacencyList[u->value].linkedList;

            while (curr->currentNode != nullptr) {
                Vertex *v = curr->currentNode;
                if (v->color == 0) {
                    v->color = 1;
                    v->d = u->d + 1;
                    v->f = u->f;
                    v->pi=u;
                    Q.push(v);
                }
                curr = curr->nextNode;
            }
            u->color = 2;
            printf("%d ", u->value);

        }


    }
};