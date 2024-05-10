#include "DirectedGraphsWithWeight.hpp"

using namespace std;


class BellmanFord {
public:
    BellmanFord(const string &filename) {
        DirectedGraphWithWeights G(filename);
        G.createEdges();

        G.vertices[0].d = 0;
        G.vertices[0].pi = &G.vertices[0];

        for (int i = 0; i < G.n; i++) {
            for (Edge edge: G.edges) {
                if (edge.u->d + edge.weight < edge.v->d) {
                    edge.v->d = edge.u->d + edge.weight;
                    edge.v->pi = edge.u;
                }
            }
        }

        for (Vertex i: G.vertices) {
            printf("%d : %d Parent -> %d\n", i.value, i.d, i.pi->value);
        }


    }

    BellmanFord(const string &filename, bool *findNegativeCycle) {
        DirectedGraphWithWeights G(filename);
        G.createEdges();

        G.vertices[0].d = 0;
        G.vertices[0].pi = &G.vertices[0];

        for (int i = 0; i < G.n; i++) {
            for (Edge edge: G.edges) {
                if (edge.u->d + edge.weight < edge.v->d) {
                    edge.v->d = edge.u->d + edge.weight;
                    edge.v->pi = edge.u;
                }
            }
        }

        *findNegativeCycle = false;
        for (Edge edge: G.edges) {
            if (edge.u->d + edge.weight < edge.v->d) {
                *findNegativeCycle = true;
                break;
            }
        }


        for (Vertex i: G.vertices) {
            printf("%d : %d Parent -> %d\n", i.value, i.d, i.pi->value);
        }


    }
};