#include <stdio.h>
#include <stdlib.h>
#include "QueueForGraphs.h"

typedef struct {

    int n;
    int **adjMatrix;
    int *visited;
    int index_visited;
} Graph;

Graph *createGraphUpdated() {
    Graph *graph = malloc(sizeof(Graph));
    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &(graph->n));
    graph->adjMatrix = malloc(sizeof(int *) * graph->n);
    graph->visited = malloc(sizeof(int) * graph->n);
    graph->index_visited = 0;
    for (int i = 0; i < graph->n; i++) {

        graph->adjMatrix[i] = calloc(sizeof(int), graph->n);;
    }

    int val1, val2;
    while (scanf("%d->%d", &val1, &val2))
        if (val1 == -1) break;
        else graph->adjMatrix[val1][val2] = 1;

    return graph;
}


Graph *createGraph() {
    Graph *graph = malloc(sizeof(Graph));
    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &(graph->n));

    graph->adjMatrix = malloc(sizeof(int *) * graph->n);
    graph->visited = malloc(sizeof(int) * graph->n);
    graph->index_visited = 0;

    for (int i = 0; i < graph->n; i++) {
        printf("Enter the adjacent nodes of NODE %d: ", i);
        int *mat = calloc(sizeof(int), graph->n);
        int val;
        while (scanf("%d", &val))
            if (val == -1) break;
            else mat[val] = 1;

        graph->adjMatrix[i] = mat;
    }


    return graph;
}


void printGraph(Graph *graph) {
    printf("\n  ");
    for (int i = 0; i < graph->n; i++) {
        printf("%d ", i);
    }
    printf("\n  ");
    for (int i = 0; i < graph->n; i++) {
        printf("| ");
    }
    printf("\n");

    for (int i = 0; i < graph->n; i++) {
        printf("%d-", i);

        for (int j = 0; j < graph->n; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }

        printf("\n");

    }
}


int inVisited(Graph *graph, int val) {
    for (int i = 0; i < graph->index_visited; ++i) {
        if (graph->visited[i] == val) return 1;

    }
    return 0;
}


void _breadthFirstSearch(Graph *graph, queue *q,int val) {
    if(inVisited(graph,val)) return;
    push(q,val);
    graph->visited[graph->index_visited++];

    




}


void breadthFirstSearch(Graph *graph,int val) {
    queue *q = create_queue(graph->n);
}


void depthFirstSearch(Graph *graph, int start) {

    if (inVisited(graph, start)) return;

    graph->visited[graph->index_visited++] = start;
    printf("%d ", start);
    for (int i = 0; i < graph->n; ++i) {

        if (graph->adjMatrix[start][i] == 1) {
            depthFirstSearch(graph, i);
        }


    }


}


void clearVisited(Graph *graph) {
    for (int i = 0; i < graph->n; i++) {
        free(&(graph->visited[i]));
    }
    graph->visited = malloc(sizeof(int) * graph->n);
}


int main() {
    Graph *g = createGraphUpdated();
    printGraph(g);
    depthFirstSearch(g, 1);
    return 0;
}
