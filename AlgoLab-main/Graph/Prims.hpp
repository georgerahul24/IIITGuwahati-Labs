#include "UndirectedGraphWithWeights.hpp"
#include "vector"

using namespace std;

//TODO: Write the order in prims
class Prims {
public:


    bool inList(Edge *edge, vector<Vertex *> *vertices) {

        for (auto vertex: *vertices) {
            if (edge->u == vertex || edge->v == vertex) return true;
        }
        return false;

    }

    bool inList(Vertex *ver, vector<Vertex *> *vertices) {

        for (auto vertex: *vertices) {
            if (ver == vertex) return true;
        }
        return false;

    }

    Edge *findMinEdge(vector<Edge *> *edges, vector<Vertex *> *verticesInS) {
        int min = INT32_MAX;
        Edge *minEdge = nullptr;

        for (auto edge: *edges) {
            if (inList(edge->u, verticesInS) && !inList(edge->v, verticesInS) && edge->weight < min) {
                minEdge = edge;
                min = edge->weight;
            }
            if (inList(edge->v, verticesInS) && !inList(edge->u, verticesInS) && edge->weight < min) {
                minEdge = edge;
                min = edge->weight;
            }
        }
        return minEdge;
    }

    void cut(vector<Edge *> *SC, vector<Vertex *> *verticesInS) {
        auto it = SC->begin();


        while (it != SC->end()) {

            if (inList((*it)->u, verticesInS) && inList((*it)->v, verticesInS)) {
                it = SC->erase(it);
            }
            ++it;
        }
    }


    Prims(const string &filename) {
        UndirectedGraphWithWeights G(filename);
        G.printAdjacencyMatrix();
        G.createEdges();
        vector<Edge *> SC; // S complement
        for (Edge edge: G.edges) {
            SC.push_back(new Edge(edge)); //Copying to SC
        }
        vector<Edge *> S; // S
        vector<Vertex *> verticesInS;

        int numberOfEdges = 0;
        verticesInS.push_back(&G.vertices[0]);
        while (numberOfEdges < G.n - 1 && !SC.empty()) {
            //printEdges(&SC);
            Edge *minEdge = findMinEdge(&SC, &verticesInS);
            S.push_back(minEdge);
            verticesInS.push_back(minEdge->v);
            verticesInS.push_back(minEdge->u);
            cut(&SC, &verticesInS);
            numberOfEdges++;

            // printf("----------\n");

        }
        printEdges(&S);

    }

    void printEdges(vector<Edge *> *S) {

        for (auto edge: *S) {
            printf("%d -> %d (%d)\n", edge->v->value, edge->u->value, edge->weight);

        }
    }
};