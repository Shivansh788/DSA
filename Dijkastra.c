#include <stdio.h>
#include <limits.h>

// Define the number of vertices in the graph
#define V 3

//find the vertex with the minimum distance value, from the set of vertices not yet included in the shortest path tree
int minDistance(int dist[], int sptSet[]) {
    int min = INT_MAX, min_index;
    
    // Iterate over all vertices to find the vertex with the minimum distance value
    for (int v = 0; v < V; v++) {
        // If the vertex is not included in the shortest path tree and the distance to it is less than the current minimum
        if (sptSet[v] == 0 && dist[v] <= min) {
            min = dist[v];    // Update the minimum distance
            min_index = v;    // Update the index of the vertex with the minimum distance
        }
    }
    return min_index;
}

// print the final answer array
void printSolution(int dist[]) {
    printf("Vertex \t Distance from Source\n");
    // Iterate over all vertices and print their distance from the source
    for (int i = 0; i < V; i++) {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

// Function that implements Dijkstra's single source shortest path algorithm for a graph represented using an adjacency matrix representation
void dijkstra(int graph[V][V], int src) {
    int dist[V];    // The output array. dist[i] will hold the shortest distance from src to i
    int sptSet[V];  // sptSet[i] will be 1 if vertex i is included in shortest path tree or shortest distance from src to i is finalized

    // Initialize all distances as INFINITE and sptSet[] as false
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;  // Set distance of all vertices to infinity
        sptSet[i] = 0;      // Set all vertices as not included in shortest path tree
    }
    
    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find the shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not yet processed
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = 1;
        
        // Update dist value of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++) {
            // Updating dist[v] if it is not in sptSet, there is an edge from u to v,
            // and if the total weight of path from src to v through u is smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Printing the final answer array
    printSolution(dist);
}

int main() {
    int graph[V][V];
    
    // Taking graph input from the user
    printf("Enter the adjacency matrix of the graph (%d x %d):\n", V, V);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    
    //Enter source vertex
    int src;
    printf("Enter the source vertex: ");
    scanf("%d", &src);
    
    // Run Dijkstra's algorithm from the source vertex provided by the user
    dijkstra(graph, src);
    
    return 0;
}
