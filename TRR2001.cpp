#include <iostream>
#include <vector>
#include <cstdio>

int n, u, v;
std::vector<std::vector<int>> adj;
bool visited[101];
std::vector<int> path;
bool found;

int countLength(int u, int v)
{
    int count {0};
    for(int w = 1; w <= n; w++)
    {
        if(adj[u][w] == 1 && adj[w][v] == 1) count++;
    }
    return count;
}

void dfs(int current)
{
    if(found) return;
    
    if(current == v)
    {
        found = true;
        return;
    }

    for(int w = 1; w <= n; w++)
    {
        if(adj[current][w] == 1 && !visited[w])
        {
            visited[w] = true;
            path.push_back(w);
            dfs(w);
            if(found) return;

            path.pop_back();
            visited[w] = false;
        }
    }
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
        found = false;
        visited[u] = true;
        path.push_back(u);

        dfs(u);

        if(!found) std::cout << 0 << "\n";

        else
        {
            int length = (int)path.size();
            for(int i = 0; i < length; i++)
            {
                std::cout << path[i];
                if(i < length - 1) std::cout << " ";
            }
            std::cout << "\n";
        }
    }


    return 0;
}
