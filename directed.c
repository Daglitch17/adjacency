#include <stdio.h>
#include <stdlib.h>

struct Node {
    int dest;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjLists;
};

struct Node* createNode(int dest) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(struct Node*));

    for (int i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

void printGraph(struct Graph* graph, char vertices[]) {
    for (int i = 0; i < graph->numVertices; i++) {
        struct Node* temp = graph->adjLists[i];
        printf("%c -> ", vertices[i]);
        while (temp) {
            printf("%c ", vertices[temp->dest]);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    char vertices[4] = {'A', 'B', 'C', 'D'};
    struct Graph* graph = createGraph(4);

    addEdge(graph, 0, 1); // A->B
    addEdge(graph, 0, 2); // A->C
    addEdge(graph, 1, 3); // B->D

    printf("Adjacency List (Directed Graph):\n");
    printGraph(graph, vertices);

    return 0;
}
