#include <stdio.h>
#include <stdlib.h>

#define V 4  

void createAdjacencyMatrix(int matrix[V][V]) {
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            matrix[i][j] = 0;
        }
    }
    
    matrix[0][1] = 1;  // A-B
    matrix[1][0] = 1;  // B-A (undirected)
    
    matrix[0][2] = 1;  // A-C
    matrix[2][0] = 1;  // C-A (undirected)
    
    matrix[1][3] = 1;  // B-D
    matrix[3][1] = 1;  // D-B (undirected)
}

void displayMatrix(int matrix[V][V]) {
    char vertices[] = {'A', 'B', 'C', 'D'};
    
    printf("Adjacency Matrix:\n\n");
    
    printf("    ");
    for(int i = 0; i < V; i++) {
        printf("%c ", vertices[i]);
    }
    printf("\n");
    
    for(int i = 0; i < V; i++) {
        printf("%c:  ", vertices[i]);
        for(int j = 0; j < V; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int adjMatrix[V][V];
    
    printf("UNDIRECTED GRAPH\n");
    createAdjacencyMatrix(adjMatrix);
    displayMatrix(adjMatrix);
    
    return 0;
}
