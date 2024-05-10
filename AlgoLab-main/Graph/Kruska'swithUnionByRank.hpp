#include "UndirectedGraphWithWeights.hpp"
#include "vector"
#include "algorithm"

using namespace std;

bool compareEdge(Edge i1, Edge i2) {
    return (i1.weight > i2.weight);
}

typedef struct TreeNode {
    Vertex *value;
    TreeNode *parent;
    int rank;

    TreeNode(Vertex *value, TreeNode *parent, int rank) {
        this->value = value;
        this->parent = parent;
        this->rank = rank;
    }

    TreeNode() {

    };

    TreeNode* findRoot() {
        TreeNode* curr = this;
        while (curr->parent != curr) {
            curr = curr->parent;
        }
        return curr;
    }


} TreeNode;


class Kruskal {
public:
    TreeNode *getRepresentative(Vertex *vertex, vector<TreeNode *> *trees) {
        TreeNode *verte;
        for (auto tree: *trees) {
            if (tree->value == vertex) {
                verte = tree;
            }
        }
        auto ver = verte->findRoot();
        if (ver != nullptr) {
            return ver;
        }
    }


    Kruskal(const string &filename) {
        UndirectedGraphWithWeights G(filename);
        vector<TreeNode *> trees;
        for (int i = 0; i < G.n; i++) {
            auto newDL = new TreeNode();
            newDL->parent = newDL;
            newDL->value = &G.vertices[i];
            newDL->rank = 0;
            trees.push_back(newDL);
        }

        G.createEdges();
        sort(G.edges.begin(), G.edges.end(), compareEdge);
        int numberOfEdges = 0;
        vector<Edge> minEdges;
        while (numberOfEdges < G.n - 1) {
            auto e = G.edges.back();
            G.edges.pop_back();
            auto ru = getRepresentative(e.u, &trees);
            auto rv = getRepresentative(e.v, &trees);
            if (ru == rv) {
                continue;
            } else {
                //Different Representatives
                if (ru->rank > rv->rank) {
                    rv->parent = ru->parent;
                } else if (rv->rank > ru->rank) {
                    ru->parent = rv->parent;
                } else {
                    ru->parent = rv->parent;
                    ru->rank++;
                }
                numberOfEdges++;
                minEdges.push_back(e);


            }

        }

        for (auto edge: minEdges) {
            printf("%d -> %d (%d)\n", edge.u->value, edge.v->value, edge.weight);
        }

    }

};