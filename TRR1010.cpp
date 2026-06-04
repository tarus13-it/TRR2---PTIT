#include <iostream>
#include <vector>
#include <cstdio>
int main()
{
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    int t, n;
    std::cin >> t >> n;
    std::vector<std::vector<int>> matrix(n + 1, std::vector<int> (n + 1));
    std::vector<int> degree(n + 1, 0);
    std::vector<std::pair<int, int>> edges;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            std::cin >> matrix[i][j];
            if(matrix[i][j] > 0 && matrix[i][j] <= 50 && j > i) 
            {
                degree[i]++;
                degree[j]++;
                edges.push_back({i, j});
            }
        }
    }

    if(t == 1)
    {
        for(int i = 1; i <= n; i++)
        {
            std::cout << degree[i];
            if(i < n) std::cout << " ";
        }
        std::cout << "\n";
    }

    else {
        int m = edges.size();
        std::vector<std::vector<int>> a(m);
        for(int i = 0; i < m; i++)
        {
            int u = edges[i].first;
            int v = edges[i].second;
            a[i].push_back(u);
            a[i].push_back(v);
            a[i].push_back(matrix[u][v]);
        }

        std::cout << n << " " << m << "\n";
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                std::cout << a[i][j];
                if(j < 2) std::cout << " ";
            }
            std::cout << "\n";
        }
    }

    return 0;
}
