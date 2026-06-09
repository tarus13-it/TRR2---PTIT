#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

int n;
std::vector<std::vector<int>> adj;
std::vector<bool> visited;
std::vector<int> component;

void dfs(int u)
{
    visited[u] = true;
    component.push_back(u);
    for(int w = 1; w <= n; w++)
    {
        if(adj[u][w] == 1 && visited[w] == false)
        {
            dfs(w);
        }
    }
}

int main()
{
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);

    std::cin >> n;
    adj.resize(n + 1, std::vector<int> (n + 1));
    visited.resize(n + 1, false);

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            std::cin >> adj[i][j];
        }
    }
    std::vector<std::vector<int>> components;
    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            component.clear();
            dfs(i);
            std::sort(component.begin(), component.end());
            components.push_back(component);
        }
    }

    std::cout << (int)components.size() << "\n";
    for(int i = 0; i < (int)components.size(); i++)
    {
        for(int j = 0; j < (int)components[i].size(); j++)
        {
            std::cout << components[i][j];
            if(j < (int)components[i].size() - 1) std::cout << " ";
        }
        if(i < (int)components.size() - 1) std::cout << "\n";
    }

    return 0;
}
