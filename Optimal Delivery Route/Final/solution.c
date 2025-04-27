#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX

int adj[MAX][MAX], dist[MAX], visited[MAX];
int n;

void reset() {
    for (int i = 0; i < MAX; i++) {
        dist[i] = INF;
        visited[i] = 0;
        for (int j = 0; j < MAX; j++)
            adj[i][j] = 0;
    }
}

void dijkstra(int src) {
    dist[src] = 0;
    for (int i = 0; i < n; i++) {
        int u = -1;
        for (int j = 0; j < n; j++)
            if (!visited[j] && (u == -1 || dist[j] < dist[u]))
                u = j;

        if (u == -1 || dist[u] == INF) break;

        visited[u] = 1;

        for (int v = 0; v < n; v++)
            if (adj[u][v] && dist[u] + adj[u][v] < dist[v])
                dist[v] = dist[u] + adj[u][v];
    }
}

int main() {
    int m, src;
    scanf("%d", &n);      // Number of nodes
    scanf("%d", &m);      // Number of edges

    reset();

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        u--; v--; // convert to 0-based indexing
        adj[u][v] = adj[v][u] = w;
    }

    scanf("%d", &src);
    src--; // convert to 0-based indexing

    dijkstra(src);

    for (int i = 0; i < n; i++)
        printf("%d ", dist[i] == INF ? -1 : dist[i]);

    return 0;
}
