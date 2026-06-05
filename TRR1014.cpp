#include <iostream>
#include <cstdio>
#include <vector>

int main()
{
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    int t, n;
    std::cin >> t >> n;
    std::vector<std::vector<int>> matrix(n + 1, std::vector<int> (n + 1));
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            std::cin >> matrix[i][j];
        }
    }

    if(t == 1)
    {
        std::vector<std::vector<int>> degree(n + 1, std::vector<int> (3, 0));
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(matrix[i][j] == 1)
                {
                    degree[i][2]++;
                    degree[j][1]++;
                }
            }
        }

        for(int i = 1; i <= n; i++)
        {
            std::cout << degree[i][1] << " " << degree[i][2] << "\n";
        }
    }

    else {
        std::vector<std::pair<int, int>> edges;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(matrix[i][j] == 1)
                {
                    edges.push_back({i, j});
                }
            }
        }

        int eSize = edges.size();
        std::vector<std::vector<int>> a(n + 1, std::vector<int> (eSize + 1, 0));
        for(int i = 1; i <= eSize; i++)
        {
            a[edges[i - 1].first][i]++;
            a[edges[i - 1].second][i]--;
        }
        
        std::cout << n << " " << eSize << "\n";
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= eSize; j++)
            {
                std::cout << a[i][j];
                if(j < eSize) std::cout << " ";
            }
            std::cout << "\n";
        }
    }

    return 0;
}
