#include <iostream>
#include <vector>
#include <fstream>

int main()
{
    std::ifstream IN("DT.INP");
    std::ofstream OUT("DT.OUT");

    int t, n;
    IN >> t >> n;

    std::vector<std::vector<int>> a(n + 1, std::vector<int> (n + 1));
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            IN >> a[i][j];
        }
    }

    if(t == 1)
    {
        for(int i = 1; i <= n; i++)
        {
            int bac {0};
            for(int j = 1; j <= n; j++)
            {
                bac += a[i][j];
            }
            OUT << bac;
            if(i < n) OUT << " ";
        }
        OUT << "\n";
    }

    else
    {
        std::vector<std::pair<int, int>> edges;
        for(int i = 1; i <= n; i++)
        {
            for(int j = i + 1; j <= n; j++)
            {
                if(a[i][j]) edges.push_back({i, j});
            }
        }

        int eSize = edges.size();
        std::vector<std::vector<int>> matrix(n + 1, std::vector<int> (eSize + 1, 0));
        for(int k = 1; k <= eSize; k++)
        {
            matrix[edges[k - 1].first][k]++;
            matrix[edges[k - 1].second][k]++;
        }
        OUT << n << " " << eSize << "\n";
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= eSize; j++)
            {
                OUT << matrix[i][j];
                if(j < eSize) OUT << " ";
            }
            OUT << "\n";
        }
    }

    IN.close();
    OUT.close();
    return 0;
}