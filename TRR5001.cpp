#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

const int INF = 10000;
int n, s, t;
int adj[105][105];

int main()
{
    freopen("DN.INP", "r", stdin);
    freopen("DN.OUT", "w", stdout);

    std::cin >> n >> s >> t;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            std::cin >> adj[i][j];

    std::vector<int> dist(n + 1, INF);
    std::vector<int> parent(n + 1, -1);
    std::vector<bool> visited(n + 1, false);
    dist[s] = 0;

    for (int iter = 0; iter < n; iter++)
    {
        // chọn đỉnh chưa thăm có dist nhỏ nhất
        int u = -1;
        for (int i = 1; i <= n; i++)
            if (!visited[i] && (u == -1 || dist[i] < dist[u]))
                u = i;

        if (u == -1 || dist[u] == INF) break;
        visited[u] = true;

        // cập nhật dist các đỉnh kề
        for (int v = 1; v <= n; v++)
        {
            if (!visited[v] && adj[u][v] < INF)
            {
                if (dist[u] + adj[u][v] < dist[v])
                {
                    dist[v] = dist[u] + adj[u][v];
                    parent[v] = u;
                }
            }
        }
    }

    if (dist[t] == INF)
    {
        std::cout << 0 << "\n";
    }
    else
    {
        std::cout << dist[t] << "\n";
        // truy vết đường đi
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
