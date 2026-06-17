#include <iostream>
#include <cstdio>
#include <vector>

int n, u;
std::vector<std::vector<int>> adj;
std::vector<bool> visited;
std::vector<int> path;
std::vector<std::vector<int>> result;

void dfs(int current)
{
    if((int)path.size() == n)
    {
        if(adj[current][u])
        {
            std::vector<int> circuit(path);
            circuit.push_back(u);
            result.push_back(circuit);
        }
        return;
    }
    
    for(int w = 1; w <= n; w++)
    {
        if(adj[current][w] && !visited[w])
        {
            visited[w] = true;
            path.push_back(w);
            dfs(w);
            path.pop_back();
            visited[w] = false;
        }
    }
}

int man()
{
    freopen("CT.INP", "r", stdin);
    freopen("CT.OUT", "w", stdout);

    std::cin >> n >> u;
    adj.resize(n + 1, std::vector<int> (n + 1));
    visited.resize(n + 1, false);

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++) std::cin >> adj[i][j];
    }

    visited[u] = true;
    path.push_back(u);
    dfs(u);

    if(result.empty()) std::cout << 0 << "\n";
    else
     {
        for(auto& circuit : result)
        {
            for(int i = 0; i < (int)circuit.size(); i++)
            {
                if(i > 0) std::cout << " ";
                std::cout << circuit[i];
            }
            std::cout << "\n";
        }
        std::cout << (int)result.size() << "\n";
     }

    return 0;
}
