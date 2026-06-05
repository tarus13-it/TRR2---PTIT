#include <iostream>
#include <vector>
#include <cstdio>

int main()
{
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    int t, n;
    std::cin >> t >> n;
    std::vector<std::vector<int>> matrix(n + 1, std::vector<int> (n + 1, 0));
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

        for(int k = 1; k <= n; k++)
        {
            std::cout << degree[k][1] << " " << degree[k][2] << "\n";
        }
    }

    else {
        std::vector<std::pair<int, int>> edges;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(matrix[i][j]) edges.push_back({i, j});
            }
        }

        std::cout << n << " " << edges.size() << "\n";
        for(auto& x : edges)
        {
            std::cout << x.first << " " << x.second << "\n";
        }
    }

    return 0;
}
