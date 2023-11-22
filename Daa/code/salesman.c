#include <stdio.h>
#include <limits.h>

#define N 4
int min(int a, int b)
{
    return (a < b) ? a : b;
}
int tsp(int graph[N][N], int mask, int pos, int dp[N][1 << N])
{
    if (mask == (1 << N) - 1)
    {
        return graph[pos][0];
    }

    if (dp[pos][mask] != -1)
    {
        return dp[pos][mask];
    }

    int minCost = INT_MAX;

    for (int city = 0; city < N; city++)
    {
        if ((mask & (1 << city)) == 0)
        {
            int newCost = graph[pos][city] + tsp(graph, mask | (1 << city), city, dp);
            minCost = min(minCost, newCost);
        }
    }

    dp[pos][mask] = minCost;
    return minCost;
}

int main()
{
    int graph[N][N] = {{0, 10, 15, 20},
                       {5, 0, 9, 10},
                       {6, 13, 0, 12},
                       {8, 8, 9, 0}};

    int dp[N][1 << N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < (1 << N); j++)
        {
            dp[i][j] = -1;
        }
    }

    int mask = 1;
    int tour_length = tsp(graph, mask, 0, dp);

    printf("Optimal Tour Length: %d\n", tour_length);

    return 0;
}