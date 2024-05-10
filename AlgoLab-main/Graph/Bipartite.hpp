#include "DirectedGraphWithoutWeights.hpp"
#include "queue"

using namespace std;

class Bipartite {
public:
    int currentColor = 3;

    explicit Bipartite(const string &filename, bool *isBipartite) {

        *isBipartite = true;
        DirectedGraph G(filename);
        G.createAdjacencyListFromMatrix();
        printf("BFS\n");

        for (int i = 0; i < G.n; i++) {
            G.vertices[i].color = 0;
            G.vertices[i].d = INFINITY;
            G.vertices[i].f = 0;
        }

        G.vertices[0].color = 3;
        G.vertices[0].d = 0;
        G.vertices[0].f = 0;

        queue<Vertex *> Q;
        Q.push(&G.vertices[0]);

        while (!Q.empty()) {
            Vertex *u = Q.front();
            Q.pop();

            Node<Vertex> *curr = G.adjacencyList[u->value].linkedList;
            u->color = (currentColor == 3 ? 4 : 3);
            currentColor = (currentColor == 3 ? 4 : 3);

            while (curr->currentNode != nullptr) {
                Vertex *v = curr->currentNode;
                if (v->color == 0) {
                    v->color = currentColor;
                    v->d = u->d + 1;
                    v->f = u->f;
                    v->pi = u;
                    Q.push(v);
                } else if (v->color == u->color) {
                    *isBipartite = false;
                    break;
                }
                curr = curr->nextNode;
            }


            printf("%d ", u->value);

        }


    }


};