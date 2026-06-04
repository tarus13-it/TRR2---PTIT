#include <iostream>
#include <vector>

int main()
{
    int t, n;
    std::cin >> t >> n;

    std::vector<std::vector<int>> adj(n + 1);
    std::vector<int> degree(n + 1);

    for(int i = 1; i <= n; i++)
    {
        int k;
        std::cin >> k;
        degree[i] = k;

        for(int j = 0; j < k; j++)
        {
            int v;
            std::cin >> v;
            adj[i].push_back(v);
        }
    }

    if(t == 1)
    {
        for(int i = 1; i <= n; i++)
        {
            std::cout << degree[i];
            if(i < n) std::cout << ' ';
        }
        std::cout << '\n';
    }
    else
    {
        std::vector<std::pair<int, int>> edges;

        for(int u = 1; u <= n; u++)
        {
            for(int v : adj[u])
            {
                if(v > u)
                {
                    edges.push_back({u, v});
                }
            }
        }

        int m = edges.size();

        std::vector<std::vector<int>> matrix(
            n + 1,
            std::vector<int>(m + 1, 0)
        );

        for(int i = 0; i < m; i++)
        {
            int u = edges[i].first;
            int v = edges[i].second;

            matrix[u][i + 1] = 1;
            matrix[v][i + 1] = 1;
        }

        std::cout << n << ' ' << m << '\n';

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                std::cout << matrix[i][j];
                if(j < m) std::cout << ' ';
            }
            std::cout << '\n';
        }
    }

    return 0;
}
