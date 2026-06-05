#include <iostream>
#include <cstdio>
#include <vector>

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
        std::vector<std::vector<int>> neighbor(n + 1);
        for(int i = 1; i <= m; i++)
        {
            neighbor[edges[i].first].push_back(edges[i].second);
        }

        std::cout << n << "\n";
        for(int i = 1; i <= n; i++)
        {
            int nSize = neighbor[i].size();
            std::cout << nSize << " ";
            for(int j = 1; j <= nSize; j++)
            {
                std::cout << neighbor[i][j - 1];
                if(j < nSize) std::cout << " ";
            }
            std::cout << "\n";
        }
    }

    return 0;
}
