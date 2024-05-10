#include "UndirectedGraphWithWeights.hpp"
#include "DoublyLinkedList.hpp"
#include "vector"
#include "algorithm"

using namespace std;

bool compareEdge(Edge i1, Edge i2) {
    return (i1.weight > i2.weight);
}

class Kruskal {
public:
    Vertex *getRepresentative(Vertex *vertex, vector<DoublyLinkedList> *linkedLists, int *index) {

        for (auto linkedList: *linkedLists) {

            auto ver = linkedList.find(vertex);
            if (ver != nullptr) {
                return ver->representative;
            }
            (*index)++;
        }
    }


    Kruskal(const string &filename) {
        UndirectedGraphWithWeights G(filename);
        vector<DoublyLinkedList> linkedLists;
        for (int i = 0; i < G.n; i++) {
            auto newDL = DoublyLinkedList();
            newDL.push_back(&G.vertices[i], &G.vertices[i]);
            newDL.head->next = nullptr;
            linkedLists.push_back(newDL);
        }

        G.createEdges();
        sort(G.edges.begin(), G.edges.end(), compareEdge);
        int numberOfEdges = 0;
        vector<Edge> minEdges;
        while (numberOfEdges < G.n - 1) {
            auto e = G.edges.back();
            G.edges.pop_back();
            int index1 = 0, index2 = 0;
            auto ru = getRepresentative(e.u, &linkedLists, &index1);
            auto rv = getRepresentative(e.v, &linkedLists, &index2);
            if (ru == rv) {
                continue;
            } else {
                //Different Representatives
                DoublyLinkedList::mergeAndChangeRepresentative(&linkedLists.at(index1), &linkedLists.at(index2));
                linkedLists.erase(linkedLists.begin() + index2);
                numberOfEdges++;
                minEdges.push_back(e);
            }

        }

        for (auto edge: minEdges) {
            printf("%d -> %d (%d)\n", edge.u->value, edge.v->value, edge.weight);
        }

    }

};