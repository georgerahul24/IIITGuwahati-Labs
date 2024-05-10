#include "DirectedGraphWithoutWeightsVer2.hpp"

using namespace std;



class TypesOfEdges {
public:
    TypesOfEdges(const string &filename) {
        DirectedGraph G(filename);


    }


    bool TreeEdge(Edge *edge) {
        return (edge->u->d < edge->v->d && edge->v->f < edge->u->f);
    }

    bool BackEdge(Edge *edge) {
        return edge->v->d < edge->u->d < edge->u->f < edge->v->f;
    }

    bool CrossEdge(Edge *edge) {
        return edge->v->d < edge->v->f < edge->u->d < edge->u->f;
    }


};



