/* Implement All Pair Shortest paths problem using Floyd’s algorithm.*/
#include <stdio.h>

int V;

void printSolution(int dist[][V]);
void floydWarshall(int dist[][V]) {
    int i, j, k;
    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    printSolution(dist);
}

void printSolution(int dist[][V]) {
    printf("The following matrix shows the shortest distances between every pair of vertices:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == 999) {
                printf("\t999");
            } else {
                printf("%7d", dist[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &V);
    int graph[V][V];
    
    printf("Enter the adjacency matrix (Enter 999 for the infinite edges):\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    
    floydWarshall(graph);
    
    return 0;
}
