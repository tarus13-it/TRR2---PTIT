#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

const int INF = 10000;
int n, s, t;
int adj[105][105];

int main()
{
    freopen("BN.INP", "r", stdin);
    freopen("BN.OUT", "w", stdout);

    std::cin >> n >> s >> t;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            std::cin >> adj[i][j];

    std::vector<int> dist(n + 1, INF);
    std::vector<int> parent(n + 1, -1);
    dist[s] = 0;

    // n-1 lần relaxation
    for (int iter = 0; iter < n - 1; iter++)
        for (int u = 1; u <= n; u++)
            for (int v = 1; v <= n; v++)
                if (adj[u][v] < INF && dist[u] < INF)
                    if (dist[u] + adj[u][v] < dist[v])
                    {
                        dist[v] = dist[u] + adj[u][v];
                        parent[v] = u;
                    }

    // kiểm tra chu trình âm
    bool negCycle = false;
    for (int u = 1; u <= n; u++)
        for (int v = 1; v <= n; v++)
            if (adj[u][v] < INF && dist[u] < INF)
                if (dist[u] + adj[u][v] < dist[v])
                {
                    negCycle = true;
                    break;
                }

    if (negCycle)
    {
        std::cout << -1 << "\n";
    }
    else if (dist[t] == INF)
    {
        std::cout << 0 << "\n";
    }
    else
    {
        std::cout << dist[t] << "\n";
        std::vector<int> path;
        for (int cur = t; cur != -1; cur = parent[cur])
            path.push_back(cur);
        std::reverse(path.begin(), path.end());
        for (int i = 0; i < (int)path.size(); i++)
        {
            if (i > 0) std::cout << " ";
            std::cout << path[i];
        }
        std::cout << "\n";
    }
    return 0;
}
