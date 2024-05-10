#include "UndirectedGraphWithWeightsVer2.hpp"
#include "vector"
#include "set"
#include "queue"

using namespace std;


class Dijstra {

    struct Comparator {
        bool operator()(const Vertex *a, const Vertex *b) const {
            return a->d > b->d;
        }
    };

    void printSet(set<Vertex *> *s) {
        for (auto ver: *s) {
            printf("|%d-(%d)| -> ", ver->value, ver->d);
        }
        printf("\n");
    }

    void printQueue(vector<Vertex *> *s) {
        for (auto ver: *s) {
            printf("%d[%d] -> ", ver->value, ver->d);
        }
        printf("\n");
    }


public:
    Dijstra(const string &filename) {
        int sourceVertex, destinationVertex;

        printf("Enter the Source Vertex: ");
        cin >> sourceVertex;
        printf("Enter the Destination Vertex: ");
        cin >> destinationVertex;


        UndirectedGraphWithWeights G(filename);
        G.createEdges();
        G.createAdjacencyListFromMatrix();


        vector<Vertex *> pq;
        set<Vertex *> notVisited;
        set<Vertex *> visted;

        for (int i = 0; i < G.n; i++) {
            notVisited.insert(&G.vertices[i]);
            pq.push_back(&G.vertices[i]);
        }

        G.vertices[sourceVertex].d = 0;
        G.vertices[sourceVertex].pi = &G.vertices[0];

        //make_heap(pq.begin(), pq.end(), Comparator()); Now, in like constant time we can make the heap

        while (!pq.empty()) {
            Vertex *ver = pq.at(0);
            for (adjacencyListEdge v: (G.adjacencyList->at(ver->value))) {

                if (v.vertex->d > ver->d + v.weight) {
                    v.vertex->d = ver->d + v.weight;
                    v.vertex->pi = ver;
                }


            }

            pq.erase(pq.begin());
            make_heap(pq.begin(), pq.end(), Comparator());
        }
        for (Vertex i: G.vertices) {
            printf("%d : %d Parent -> %d\n", i.value, i.d, i.pi->value);
        }
        printf("The distance from the source vertex to the destination vertex is : %d",
               G.vertices.at(destinationVertex).d);

        int distance = G.vertices.at(destinationVertex).d;
        int midpoint = distance / 2;

        int vertex = -1;
        Vertex t = G.vertices.at(destinationVertex);
        while (distance >= midpoint) {

            if (distance == midpoint) {
                vertex = t.value;
                break;
            };
            distance = distance + (t.pi->d - t.d);
            t = *t.pi;
        }

        printf("\nThe Vertex t is: %d", vertex);


    }


};