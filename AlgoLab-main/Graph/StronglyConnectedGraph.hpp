#include "DirectedGraphWithoutWeightsVer2.hpp"
#include "set"
class StronglyConnectedGraph {
    int time = 0;
public:
    StronglyConnectedGraph(const string &filename) {
        DirectedGraph G(filename);
        G.createAdjacencyListFromMatrix();

        DirectedGraph *G_Inv = DirectedGraph::Inverse(&G);
        G_Inv->createAdjacencyListFromMatrix();
        vector<Vertex *> dfsList;
        DFS(&G, &dfsList);

        for (auto dfsver: dfsList) {
            printf("%d-(%d) -----", dfsver->value, dfsver->f);
        }

        set<Vertex*> visited;






    }


    void DFS(DirectedGraph *G, vector<Vertex *> *dfsList) {


        for (int i = 0; i < G->n; i++) {
            G->vertices[i].color = 0;
            G->vertices[i].d = INFINITY;
            G->vertices[i].f = 0;
        }


        for (int i = 0; i < G->n; i++) {
            if (G->vertices[i].color == 0) {
                DFS_VISIT(&G->vertices[i], dfsList, G);
            }
        }


    }

    void DFS_VISIT(Vertex *u, vector<Vertex *> *dfsList, DirectedGraph *G) {
        u->d = ++time;
        u->color = 1;

        vector<Vertex *> *list = G->adjacencyList->at(u->value);

        for (auto v: *list) {
            if (v->color == 0) {
                v->pi = u;
                DFS_VISIT(v, dfsList, G);
            }
        }
        u->color = 2;
        time++;
        u->f = time;
        dfsList->push_back(u);
    }
};
