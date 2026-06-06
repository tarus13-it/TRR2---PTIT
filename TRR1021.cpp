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
    int countSize {0};
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            std::cin >> matrix[i][j];
            if(matrix[i][j] > 0 && matrix[i][j] <= 50) countSize++;
        }
    }

    if(t == 1)
    {
        std::vector<std::vector<int>> degree(n + 1, std::vector<int> (3));
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(matrix[i][j] > 0 && matrix[i][j] <= 50)
                {
                    degree[i][2]++;
                    degree[j][1]++;
                }
            }
        }

        for(int i = 1; i <= n ; i++)
        {
            std::cout << degree[i][1] << " " << degree[i][2] << "\n";
        }
    }

    else {
        std::vector<std::vector<int>> edges(countSize + 1, std::vector<int> (4));
        int k{1};
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            { 
                if(matrix[i][j] > 0 && matrix[i][j] <= 50)
                {
                    edges[k][1] = i;
                    edges[k][2] = j;
                    edges[k][3] = matrix[i][j];
                    k++;
                }
            }
        }

        std::cout << n << " " << countSize << "\n";
        for(int i = 1; i <= countSize; i++)
        {
            std::cout << edges[i][1] << " " << edges[i][2] << " " << edges[i][3] << "\n";
        }

    }

    return 0;
}
