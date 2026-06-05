#include <vector>
#include <cstdio>
#include <iostream>

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
                if(matrix[i][j])
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
        std::vector<std::vector<int>> neighbor(n + 1);
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(matrix[i][j] == 1) neighbor[i].push_back(j);
            }
        }

        std::cout << n << "\n";
        for(int i = 1; i <= n; i++)
        {
            int nSize = neighbor[i].size();
            std::cout << nSize << " ";
            for(int j = 0; j < nSize; j++)
            {
                std::cout << neighbor[i][j];
                if(j < n - 1) std::cout << " ";
            }
            std::cout << "\n";
        }
    }

    return 0;
}
