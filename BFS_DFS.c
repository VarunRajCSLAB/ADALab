//BFS Code:
#include <stdio.h>
#include <conio.h>

int a[15][15], n;

void bfs(int);

int main() {
    int i, j, src;
    
    printf("\nEnter the no of nodes:\t");
    scanf("%d", &n);
    
    printf("\nEnter the adjacency matrix:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    
    printf("\nEnter the source node:\t");
    scanf("%d", &src);
    
    bfs(src);
    
    return 0;
}

void bfs(int src) {
    int q[15], f = 0, r = -1, vis[15], i, j;
    
    for (j = 1; j <= n; j++)
        vis[j] = 0;
    
    vis[src] = 1;
    r = r + 1;
    q[r] = src;
    
    while (f <= r) {
        i = q[f];
        f = f + 1;
        
        for (j = 1; j <= n; j++) {
            if (a[i][j] == 1 && vis[j] != 1) {
                vis[j] = 1;
                r = r + 1;
                q[r] = j;
            }
        }
    }
    
    for (j = 1; j <= n; j++) {
        if (vis[j] != 1)
            printf("\nNode %d is not reachable", j);
        else
            printf("\nNode %d is reachable", j);
    }
}


//DFS Code:
#include <stdio.h>
#include <conio.h>

int a[10][10], n, vis[10];

int dfs(int src) {
    int j;
    vis[src] = 1;
    
    for (j = 1; j <= n; j++) {
        if (a[src][j] == 1 && vis[j] != 1) {
            dfs(j);
        }
    }
    
    for (j = 1; j <= n; j++) {
        if (vis[j] != 1) {
            return 0;
        }
    }
    
    return 1;
}

int main() {
    int i, j, src, ans;
    
    for (j = 1; j <= n; j++) {
        vis[j] = 0;
    }
    
    printf("\nEnter the no of nodes:\t");
    scanf("%d", &n);
    
    printf("\nEnter the adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    
    printf("\nEnter the source node:\t");
    scanf("%d", &src);
    
    ans = dfs(src);
    
    if (ans == 1) {
        printf("\nGraph is connected\n");
    } else {
        printf("\nGraph is not connected\n");
    }
    
    getch();
    
    return 0;
}
