#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>

int n, u, v;
std::vector<std::vector<int>> adj;

int countLength(int u, int v)
{
    int count {0};
    for(int w = 1; w <= n; w++)
    {
        if(adj[u][w] == 1 && adj[w][v] == 1) count++;
    }
    return count;
}

void bfs(int u, int v)
{
    std::vector<int> parents(n + 1, -1);
    std::vector<int> visited(n + 1, false);

    std::queue<int> q;
    visited[u] = true;
    q.push(u);
    while(!q.empty())
    {
        int current = q.front();
        q.pop();
        if(current == v) break;

        for(int w = 1; w <= n; w++)
        {
            if(adj[current][w] == 1 && visited[w] == false)
            {
                visited[w] = true;
                parents[w] = current;
                q.push(w);
            }
        }
    }

    if(!visited[v])
    {
        std::cout << 0 << "\n";
        return;
    }

    std::vector<int> path;
    for(int cur = v; cur != -1; cur = parents[cur])
    {
        path.push_back(cur);
    }

    int length = (int)path.size();
    for(int i = length - 1; i >= 0; i--)
    {
        std::cout << path[i];
        if(i > 0) std::cout << " ";
    }
    std::cout << "\n";
}

int main()
{
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);

    int t;
    std::cin >> t >> n >> u >> v;
    adj.resize(n + 1, std::vector<int> (n + 1));
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            std::cin >> adj[i][j];
        }
    }

    if(t == 1)
    {
        std::cout << countLength(u, v) << "\n";
    }

    else {
        bfs(u, v);
    }

    return 0;
}
