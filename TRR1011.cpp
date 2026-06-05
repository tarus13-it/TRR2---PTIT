#include <iostream>
#include <cstdio>
#include <vector>

int main()
{
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    int t, n, m;
    std::cin >> t >> n >> m;
    std::vector<std::vector<int>> edges(m + 1);
    for(int i = 1; i <= m; i++)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        edges[i].push_back(a);
        edges[i].push_back(b);
        edges[i].push_back(c);
    }

    if(t == 1)
    {
        std::vector<int> degree(n + 1);
        for(int i = 1; i <= m; i++)
        {
            for(int j = 0; j <= 1; j++)
            {
                degree[edges[i][j]]++;
            }
        }

        for(int i = 1; i <= n; i++)
        {
            std::cout << degree[i];
            if(i < n) std::cout << " ";
        }
        std::cout << "\n";
    }

    else {
        std::vector<std::vector<int>> matrix(n + 1, std::vector<int> (n + 1, 0));
        for(int i = 1; i <= m; i++)
        {
            matrix[edges[i][0]][edges[i][1]] = edges[i][2];
            matrix[edges[i][1]][edges[i][0]] = edges[i][2];
        }

        std::cout << n << "\n";
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(matrix[i][j] == 0 && i != j) std::cout << 10000;
                else std::cout << matrix[i][j];
                if(j < n) std::cout << " ";
            }
            std::cout << "\n";
        }
    }

    return 0;
}
