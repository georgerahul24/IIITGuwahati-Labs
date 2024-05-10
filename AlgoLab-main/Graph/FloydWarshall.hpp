#include "DirectedGraphsWithWeight.hpp"

using namespace std;

class FloydWarshall {
public:
    FloydWarshall(const string &filename) {
        DirectedGraphWithWeights G(filename);
        G.createEdges();
        int arr[G.n][G.n];

        for (int i = 0; i < G.n; i++) {
            for (int j = 0; j < G.n; j++) {
                arr[i][j] = INT32_MAX;
            }
        }

        for (auto edge: G.edges) {
            arr[edge.u->value][edge.v->value] = edge.weight;
        }

        for (int i = 0; i < G.n; i++) {
            for (int j = 0; j < G.n; j++) {
                printf("%d ",arr[i][j]!=INT32_MAX?arr[i][j]:0);
            }
            printf("\n");
        }




    }
};