#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Directions: right, left, down, up
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

// Structure to store queue elements
typedef struct {
    int x, y, steps;
} Node;

// Structure to track parent nodes for path reconstruction
typedef struct {
    int x, y;
} Parent;

// Function to check if a position is valid for movement
int isValid(int x, int y, int rows, int cols, int matrix[MAX][MAX], int visited[MAX][MAX]) {
    return (x >= 0 && x < rows && y >= 0 && y < cols && matrix[x][y] == 1 && !visited[x][y]);
}

// BFS to find the shortest path and track the path
int shortestPath(int matrix[MAX][MAX], int rows, int cols, int startX, int startY, int endX, int endY, Node path[MAX * MAX]) {
    if (matrix[startX][startY] == 0 || matrix[endX][endY] == 0) 
        return -1; // If start or end is blocked, return -1 (no path)

    int visited[MAX][MAX] = {0};
    Parent parent[MAX][MAX]; // To store the parent of each cell

    Node queue[MAX * MAX];
    int front = 0, rear = 0;

    // Enqueue the starting point
    queue[rear++] = (Node){startX, startY, 0};
    visited[startX][startY] = 1;
    parent[startX][startY] = (Parent){-1, -1}; // Mark start node with no parent

    // BFS loop
    while (front < rear) {
        Node current = queue[front++];
        
        // If we reach the destination, reconstruct the path
        if (current.x == endX && current.y == endY) {
            int pathLength = current.steps;
            int px = endX, py = endY;

            // Backtrack to reconstruct the path
            for (int i = pathLength; i >= 0; i--) {
                path[i] = (Node){px, py, i};
                Parent p = parent[px][py];
                px = p.x;
                py = p.y;
            }

            return pathLength;
        }

        // Try all 4 directions
        for (int i = 0; i < 4; i++) {
            int newX = current.x + dx[i];
            int newY = current.y + dy[i];

            if (isValid(newX, newY, rows, cols, matrix, visited)) {
                visited[newX][newY] = 1;
                queue[rear++] = (Node){newX, newY, current.steps + 1};
                parent[newX][newY] = (Parent){current.x, current.y}; // Store parent
            }
        }
    }
    
    return -1; // If no path is found, return -1
}

int main() {
    int rows, cols;
    scanf("%d", &cols);
    scanf("%d", &rows);

    int matrix[MAX][MAX];
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf("%d", &matrix[i][j]);

    int startX, startY, endX, endY;
    scanf("%d", &startX);
    scanf("%d", &startY);
    scanf("%d", &endX);
    scanf("%d", &endY);

    // Convert to zero-based indexing
    startX--; startY--; endX--; endY--;

    Node path[MAX * MAX]; // Array to store the path
    int result = shortestPath(matrix, rows, cols, startX, startY, endX, endY, path);
    
    if (result == -1)
        printf("[]");
    else {
        for (int i = 0; i <= result; i++)
            printf("(%d,%d)", path[i].x + 1, path[i].y + 1); // Convert back to 1-based indexing
    }

    return 0;
}
