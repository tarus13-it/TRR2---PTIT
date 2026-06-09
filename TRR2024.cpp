#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <queue>

int n;
std::vector<std::vector<int>> adj;

int components(int skip)
{
    std::vector<bool> visited(n + 1, false);
    visited[skip] = true;
    int component = {0};

    for(int i = 1; i <= n; i++)
    {
        if(visited[i]) continue;
        component++;
        std::queue<int> q;
        visited[i] = true;
        q.push(i);

        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            for(int w = 1; w <= n; w++)
            {
                if(adj[u][w] == 1 && !visited[w])
                {
                    visited[w] = true;
                    q.push(w);
                }
            }
        }
    }
    return component;
}

int main()
{
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    std::cin >> n;
    adj.resize(n + 1, std::vector<int> (n + 1));
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++) std::cin >> adj[i][j];
    }

    int base = components(0);

    std::vector<int> result;
    for(int i = 1; i <= n; i++)
    {
        if(components(i) > base) result.push_back(i);
    }

    int rSize = result.size();
    std::cout << rSize << "\n";
    if(!result.empty())
    {
        for(int i = 0; i < rSize; i++)
        {
            std::cout << result[i];
            if(i < rSize - 1) std::cout << " ";
        }
        std::cout << "\n";
    }

    return 0;
}