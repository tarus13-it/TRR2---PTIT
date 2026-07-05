#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstdio>

int n;
std::vector<std::vector<int>> adj;
std::vector<int> component;

void bfs(int u, std::vector<std::vector<int>>& graph, std::vector<bool>& visited)
{
    std::queue<int> q;
    visited[u] = true;
    q.push(u);
    while(!q.empty())
    {
        int current = q.front();
        q.pop();
        for(int w = 1; w <= n; w++)
        {
            if(graph[current][w] == 1 && !visited[w])
            {
                q.push(w);
                visited[w] = true;
            }
        }
    }
}

bool isAllvisited(std::vector<bool>& visited)
{
    for(int i = 1; i <= n; i++)
    {
        if(!visited[i]) return false;
    }
    return true;
}

int main()
{
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    std::cin >> n;
    adj.resize(n + 1, std::vector<int> (n + 1));
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            std::cin >> adj[i][j];
        }
    }

    std::vector<std::vector<int>> uAdj(n + 1, std::vector<int> (n + 1));
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(adj[i][j]) uAdj[i][j] = uAdj[j][i] = 1;
        }
    }

    bool strong = true;
    for(int i = 1; i <= n; i++)
    {
        std::vector<bool> visited(n + 1, false);
        bfs(i, adj, visited);
        if(!isAllvisited(visited)) {strong = false; break;}
    }
    
    if(strong) std::cout << 1 << "\n";
    else
    {
        std::vector<bool> visited(n + 1, false);
        bfs(1, uAdj, visited);
        if(isAllvisited(visited)) std::cout << 2 << "\n";
        else std::cout << 0 << "\n";
    }

    return 0;
}
