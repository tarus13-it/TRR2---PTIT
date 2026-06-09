#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

int n;
std::vector<std::vector<int>> adj;
std::vector<int> disc, low, parents;
std::vector<bool> iA;
int timer;

void dfs(int u)
{
    disc[u] = low[u] = ++timer;
    int childCount = {0};

    for(int w = 1; w <= n; w++)
    {
        if(adj[u][w] == 0) continue;

        if(disc[w] == 0)
        {
            childCount++;
            parents[w] = u;
            dfs(w);

            low[u] = std::min(low[u], low[w]);

            if(parents[u] == 0 && childCount >= 2)
            {
                iA[u] = true;
            }

            if(parents[u] != 0 && low[w] >= disc[u])
            {
                iA[u] = true;
            }

        }

        else if(w != parents[u])
        {
            low[u] = std::min(low[u], disc[w]);
        }
    }
}

int main()
{
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT" , "w", stdout);
    std::cin >> n;

    adj.resize(n + 1, std::vector<int> (n + 1));
    disc.resize(n + 1, 0);
    low.resize(n + 1, 0);
    parents.resize(n + 1, 0);
    iA.resize(n + 1, false);
    timer = {0};

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++) std::cin >> adj[i][j];
    }

    for(int i = 1; i <= n; i++)
    {
        if(disc[i] == 0) dfs(i);
    }
    
    std::vector<int> result;
    for(int i = 1; i <= n; i++)
    {
        if(iA[i]) result.push_back(i);
    }

    int rSize = result.size();
    std::cout << rSize << "\n";
    for(int i = 0; i < rSize; i++)
    {
        std::cout << result[i];
        if(i < rSize - 1) std::cout << " ";
    }
    std::cout << "\n";

    return 0;
}
