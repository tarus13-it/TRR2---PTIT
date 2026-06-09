#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstdio>

int n;
std::vector<std::vector<int>> adj;
std::vector<bool> visited;

std::vector<int> bfs(int u)
{
    std::vector<int> component;
    std::queue<int> q;
    visited[u] = true;
    q.push(u);
    while(!q.empty())
    {
        int current = q.front();
        q.pop();
        component.push_back(current);
        for(int w = 1; w <= n; w++)
        {
            if(adj[current][w] == 1 && visited[w] == false)
            {
                visited[w] = true;
                q.push(w);

            }
        }
    }
    std::sort(component.begin(), component.end());
    return component;
}

int main()
{
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);

    std::cin >> n;
    adj.resize(n + 1, std::vector<int> (n + 1));
    visited.resize(n + 1, false);
    std::vector<std::vector<int>> components;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            std::cin >> adj[i][j];
        }
    }
    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            components.push_back(bfs(i));
        }
    }


    std::cout << (int)components.size() << "\n";
    for(int i = 0; i < (int)components.size(); i++)
    {
        for(int j = 0; j < (int)components[i].size(); j++)
        {
            std::cout << components[i][j] << " ";
        }
        std::cout << "\n";
    }

    
    return 0;
}
