#include <stdio.h>

int G[10][10], visited[10];
void display(int v);
void DFS(int i, int n);
void bfs(int v, int n);

int main()
{
    int i, j, n, ch;
    printf("\nEnter number of vertices:");
    scanf("%d", &n);
    printf("\nEnter adjecency matrix of the graph:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &G[i][j]);
    printf("Enter 1 for BFS\nEnter 2 for DFS\nEnter 3 for Exit\n");
    ch = 0;
    while (ch != 3)
    {
        printf("Enter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            for (i = 0; i < n; i++)
                visited[i] = 0;
            bfs(0, n);
            printf("\n");
            break;
        case 2:
            for (i = 0; i < n; i++)
                visited[i] = 0;
            DFS(0, n);
            printf("\n");
            break;
        case 3:
        return 0;
        break;
        default:
            printf("Wrong Choice\n");
            break;
        }
    }
    return 0;
}

void bfs(int v, int n)
{
    int queue[1000], front = -1, rear = -1;
    visited[v] = 1;
    queue[++rear] = v;
    while (front != rear)
    {
        int currentVertex = queue[++front];
        printf("%d\t", currentVertex);

        for (int i = 0; i < n; i++)
        {
            if (G[currentVertex][i] && !visited[i])
            {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
}

void display(int v)
{
    printf("\t%d", v);
}

void DFS(int i, int n)
{
    int j;
    display(i);
    visited[i] = 1;
    for (j = 0; j < n; j++)
        if (!visited[j] && G[i][j] == 1)
            DFS(j, n);
}
