#include "vector"
#include "queue"
#include "UndirectedGraphWithWeightsVer2.hpp"

using namespace std;


class Prims {
private:
    struct Comparator {
        bool operator()(const Vertex *a, const Vertex *b) const {
            return a->d > b->d;
        }
    };

public:
    Prims(const string &filename) {
        vector<Vertex *> minHeap;
        UndirectedGraphWithWeights G(filename);
        for (auto v: G.vertices) {
            v.d = INT32_MAX;
            v.pi = NULL;
            minHeap.push_back(&v);
        }
        G.vertices.at(0).d = 0;
        make_heap(minHeap.begin(), minHeap.end(), Comparator());

        while (!minHeap.size() == 0) {
            Vertex *u = minHeap.at(0);

            for (auto edge: G.adjacencyList->at(u->value)) {
                //find if v is in H.
                if (edge.vertex->d > edge.weight) {
                    edge.vertex->d = edge.weight;
                    edge.vertex->pi = u;
                }
            }


            minHeap.erase(minHeap.begin());
            make_heap(minHeap.begin(), minHeap.end(), Comparator());
        }


    }

};