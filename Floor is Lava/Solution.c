#include "stdio.h"
#include "stdlib.h"

int isEulerian(int **graph, int n) {
    int oddDegreeCount = 0;
    for (int i = 0; i < n; i++) {
        int degree = 0;
        for (int j = 0; j < n; j++) {
            degree += graph[i][j];
        }
        if (degree % 2 != 0) {
            oddDegreeCount++;
        }
    }
    return oddDegreeCount == 0;
}

int isConnected(int **graph, int n) {
    int *visited = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    int stack[n];
    int top = -1;

    visited[0] = 1;
    stack[++top] = 0;

    while (top != -1) {
        int v = stack[top--];
        for (int i = 0; i < n; i++) {
            if (graph[v][i] && !visited[i]) {
                visited[i] = 1;
                stack[++top] = i;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            free(visited);
            return 0;
        }
    }
    free(visited);
    return 1;
}

int isEulerianCycle(int **graph, int n) {
    if (!isConnected(graph, n)) {
        return 0;
    }
    return isEulerian(graph, n);
}

int *HierHolzerSimplified(int **graph, int n, int s) {
    int *cycle = (int *)malloc(((n*(n-1)/2) + 1) * sizeof(int));
    for (int i = 0; i < n*(n-1)/2 + 1; i++) {
        cycle[i] = -1;
    }
    int cycleIndex = 0;
    int stop = 0;
    if (isEulerianCycle(graph, n) == 0) {
        return NULL;
    }
    cycle[cycleIndex] = s;
    cycleIndex++;
    while(stop == 0){
        for(int i = 0; i < n; i++) {
            if (graph[s][i] == 1) {
                cycle[cycleIndex] = i;
                cycleIndex++;
                graph[s][i] = 0;
                graph[i][s] = 0;
                s = i;
                break;
            }
            if (i == n - 1) {
                stop = 1;
            }
        }
    }
    return cycle;
}

int **createGraph(int src[5][5], int n) {
    int **graph = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        graph[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            graph[i][j] = src[i][j];
        }
    }
    return graph;
}


int main(){
// Example usage
int n = 5; // Number of vertices
int s = 2; // Starting vertex
int src[5][5] = {
    {0, 1, 1, 0, 0},
    {1, 0, 1, 0, 0},
    {1, 1, 0, 1, 1},
    {0, 0, 1, 0, 1},
    {0, 0, 1, 1, 0}
};
int **graph = createGraph(src, n);

int *cycle = HierHolzerSimplified((int **)graph, n, s);
if (cycle != NULL) {
    printf("YES\n");
    for (int i = 0; cycle[i] != -1; i++) {
        printf("%d ", cycle[i]);
    }
} else {
    printf("NO");
}
free(cycle);
return 0;

//made by Boudib Mohamed Khalil aka S7a_

}