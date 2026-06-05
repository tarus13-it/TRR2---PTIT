#include <iostream>
#include <vector>
#include <cstdio>

int main()
{
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    
    int t, n, m;
    std::cin >> t >> n >> m;
    std::vector<std::pair<int, int>> edges(m + 1);
    for(int i = 1; i <= m; i++)
    {
        int a, b;
        std::cin >> a >> b;
        edges[i].first = a;
        edges[i].second = b;
    }

    if(t == 1)
    {
        std::vector<std::vector<int>> degree(n + 1, std::vector<int> (3, 0));
        for(int i = 1; i <= m; i++)
        {
            degree[edges[i].first][2]++;
            degree[edges[i].second][1]++;
        }

        for(int i = 1; i <= n; i++)
        {
            std::cout << degree[i][1] << " " << degree[i][2] << "\n";
        }
    }

    else {
        std::vector<std::vector<int>> matrix(n + 1, std::vector<int> (m + 1, 0));
        for(int i = 1; i <= m; i++)
        {
            matrix[edges[i].first][i]++;
            matrix[edges[i].second][i]--;
        }

        std::cout << n << " " << m << "\n";
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                std::cout << matrix[i][j];
                if(j < m) std::cout << " ";
            }
            std::cout << "\n";
        }
    }

    return 0;
}
