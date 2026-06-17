#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>

int n, s;
std::vector<std::vector<int>> adj;
std::vector<bool> visited;
std::vector<std::pair<int,int>> edges;

void dfs(int u)
{
    visited[u] = true;
    for (int w = 1; w <= n; w++)
    {
        if (adj[u][w] && !visited[w])
        {
            edges.push_back({std::min(u,w), std::max(u,w)});
            dfs(w);
        }
    }
}

void bfs(int u)
{
    std::queue<int> q;
    visited[u] = true;
    q.push(u);
    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        for (int w = 1; w <= n; w++)
        {
            if (adj[current][w] && !visited[w])
            {
                visited[w] = true;
                edges.push_back({std::min(current,w), std::max(current,w)});  // fix
                q.push(w);
            }
        }
    }
}

int main()
{
    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);

    int t;
    std::cin >> t >> n >> s;
    adj.resize(n + 1, std::vector<int>(n + 1));
    visited.resize(n + 1, false);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            std::cin >> adj[i][j];

    if (t == 1) dfs(s);
    else        bfs(s);

    // cây khung tồn tại khi đi từ s thăm được tất cả n đỉnh
    if ((int)edges.size() != n - 1)
    {
        std::cout << 0 << "\n";
    }
    else
    {
        std::cout << n - 1 << "\n";
        for (auto& e : edges)
            std::cout << e.first << " " << e.second << "\n";
    }

    return 0;
}
