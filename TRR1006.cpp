#include <iostream>
#include <vector>
#include <fstream>

int main()
{
    std::ifstream IN("DT.INP");
    std::ofstream OUT("DT.OUT");

    int t, n, m;
    IN >> t >> n >> m;
    std::vector<std::pair<int, int>> edges(m + 1);
    for(int i = 1; i <= m; i++)
    {
        int a, b;
        IN >> a >> b;
        edges[i].first = a;
        edges[i].second = b;
    }

    if(t == 1)
    {
        std::vector<int> degree(n + 1, 0);
        for(int i = 1; i <= m; i++)
        {
            degree[edges[i].first]++;
            degree[edges[i].second]++;
        }

        for(int j = 1; j <= n; j++)
        {
            OUT << degree[j];
            if(j < n) OUT << " ";
        }
        OUT << "\n";
    }

    else {
        std::vector<std::vector<int>> matrix(n + 1, std::vector<int> (m + 1, 0));
        for(int i = 1; i <= m; i++)
        {
            matrix[edges[i].first][i]++;
            matrix[edges[i].second][i]++;
        }
        OUT << n << " " << m << "\n";
        for(int j = 1; j <= n; j++)
        {
            for(int k = 1; k <= m; k++)
            {
                OUT << matrix[j][k];
                if(k < m) OUT << " ";
            }
            OUT << "\n";
        }
    }

    IN.close();
    OUT.close();
    return 0;
}
