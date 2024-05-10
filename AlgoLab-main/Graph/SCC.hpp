#include "DirectedGraphWithoutWeights.hpp"
#include "vector"
#include "DFS.hpp"

using namespace std;

class SCC {
public:
    explicit SCC(const string &filename) {

        vector<Vertex *> dfsListForG;
        DFS dfs(filename, &dfsListForG);
        DirectedGraph *G = dfs.G;
        DirectedGraph *invG = DirectedGraph::Inverse(G);
        invG->createAdjacencyListFromMatrix();

        for (auto v: dfsListForG) {
            v->color = 0;
        }

        while (!dfsListForG.empty()) {

            Vertex *u = dfsListForG.back();
            dfsListForG.pop_back();
            if (u->color == 0) {
                getSCC(u, invG,G);
            }

        }

    }

    void getSCC(Vertex *u, DirectedGraph *invG,DirectedGraph* G) {
        vector<Vertex *> dfsListForU;
        DFS_VISIT(u, &dfsListForU, invG,G,0);
        printf("SCC: ");
        for (auto v: dfsListForU) {
            printf("%d->", v->value);
        }
        printf("\n");

    }

    void DFS_VISIT(Vertex *u, vector<Vertex *> *dfsList, DirectedGraph *invG,DirectedGraph *G,int time) {
        u->d = ++time;
        u->color = 1;
        G->vertices[u->value].color=1;

        Node<Vertex> *curr = invG->adjacencyList[u->value].linkedList;

        while (curr->currentNode != nullptr) {
            Vertex *v = curr->currentNode;
            if (v->color == 0) {
                v->pi = u;
                G->vertices[v->value].color=2;
                DFS_VISIT(v, dfsList,invG,G,time);
            }
            curr = curr->nextNode;
        }
        u->color = 2;
        G->vertices[u->value].color=2;
        time++;
        u->f = time;
        dfsList->push_back(u);
    }


};