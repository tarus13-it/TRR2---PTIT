#include <iostream>
#include <cstdio>
#include <vector>

int main()
{
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    int t, n;
    std::cin >> t >> n;
    std::vector<std::vector<int>> neighbor(n + 1);
    for(int i = 1; i <= n; i++)
    {
        int a; std::cin >> a;
        for(int j = 1; j <= a; j++)
        {
            int b;
            std::cin >> b;
            neighbor[i].push_back(b);
        }
    }

    if(t == 1)
    {
        std::vector<std::vector<int>> degree(n + 1, std::vector<int> (3, 0));
        for(int i = 1; i <= n; i++)
        {
            int nSize = neighbor[i].size();
            for(int j = 1; j <= nSize; j++)
            {
                degree[i][2]++;
                degree[neighbor[i][j - 1]][1]++;
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
            int nSize = neighbor[i].size();
            for(int j = 1;j <= nSize; j++)
            {
                edges.push_back({i, neighbor[i][j - 1]});
            }
        }

        int eSize = edges.size();
        std::vector<std::vector<int>> matrix(n + 1, std::vector<int> (eSize + 1, 0));

        for(int i = 1; i <= eSize; i++)
        {
            matrix[edges[i - 1].first][i]++;
            matrix[edges[i - 1].second][i]--;
        }

        std::cout << n << " " << sSize << "\n";
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= eSize; j++)
            {
                std::cout << matrix[i][j];
                if(j < eSize) std::cout << " ";
            }
            std::cout << "\n";
        }
    }

    return 0;
}
