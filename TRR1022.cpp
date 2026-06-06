#include <iostream>
#include <vector>
#include <cstdio>

int main()
{
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    int t, n, m;
    std::cin >> t >> n >> m;
    std::vector<std::vector<int>> edges(m + 1, std::vector<int> (4));
    for(int i = 1; i <= m; i++)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        edges[i][1] = a;
        edges[i][2] = b;
        edges[i][3] = c;
    }

    if(t == 1)
    {
        std::vector<std::vector<int>> degree(n + 1, std::vector<int> (3));
        for(int i = 1; i <= m; i++)
        {
            degree[edges[i][1]][2]++;
            degree[edges[i][2]][1]++;
        }

        for(int i = 1; i <= n ;i++)
        {
            std::cout << degree[i][1] << " " << degree[i][2] << "\n";
        }
    }

    else {
        std::vector<std::vector<int>> matrix(n + 1, std::vector<int> (n + 1, 10000));
        for(int i = 1; i <= n; i++)
        {
            matrix[i][i] = 0;
        }
        
        for(int i = 1; i <= m; i++)
        {
            matrix[edges[i][1]][edges[i][2]] = edges[i][3];
        }

        std::cout << n << "\n";
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                std::cout << matrix[i][j];
                if(j < n) std::cout << " ";
            }
            std::cout << "\n";
        }
    }

    return 0;
}
