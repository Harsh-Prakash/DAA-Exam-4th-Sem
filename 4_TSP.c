#include <stdio.h>
#include <limits.h>
#define MAXCITIES 10

int n;
int cost[MAXCITIES][MAXCITIES];
int minCost = INT_MAX;
int minRoute[MAXCITIES];

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void calculateCost(int route[]) {
    int currentCost = 0;
    for (int i = 0; i < n - 1; i++) {
        currentCost += cost[route[i]][route[i + 1]];
    }
    currentCost += cost[route[n - 1]][route[0]]; 
    if (currentCost < minCost) {
        minCost = currentCost;
        for (int i = 0; i < n; i++) {
            minRoute[i] = route[i];
        }
    }
}

void permute(int route[], int left, int right) {
    if (left == right) {
        calculateCost(route);
        return;
    }
    for (int i = left; i <= right; i++) {
        swap(&route[left], &route[i]);
        permute(route, left + 1, right);
        swap(&route[left], &route[i]); 
    }
}

void displayMinCostAndRoute() {
    printf("\nMinimum Cost: %d\n", minCost);
    // printf("Route: 1 -> ");
    for (int i = 0; i < n; i++) {
        printf("%d", minRoute[i] + 1); 
        if (i < n - 1) {
            printf(" -> ");
        }
    }
    printf(" -> 1\n");
}

int main() {
    printf("Enter the number of cities: ");
    scanf("%d", &n);
    printf("Enter the cost matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    int route[MAXCITIES];
    for (int i = 0; i < n; i++) {
        route[i] = i; 
    }
    permute(route, 0, n - 1);
    displayMinCostAndRoute();
    return 0;
}
