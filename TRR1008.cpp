#include <iostream>
#include <vector>
#include <fstream>

int main()
{
    std::ifstream IN("DT.INP");
    std::ofstream OUT("DT.OUT");

    int t, n;
    IN >> t >> n;
    std::vector<std::vector<int>> dAn(n + 1);
    std::vector<int> degree(n + 1);
    for(int i = 1; i <= n; i++)
    {
        int a;
        IN >> a;
        degree[i] = a;
        for(int j = 1; j <= a; j++)
        {
            int b;
            IN >> b;
            dAn[i].push_back(b);
        }
    }

    if(t == 1)
    {
        for(int i = 1; i <= n; i++)
        {
            OUT << degree[i];
            if(i < n) OUT << " ";
        }
        OUT << "\n";
    }

    else {
        std::vector<std::pair<int, int>> edges;
        for(int i = 1; i <= n; i++)
        {
            int size = degree[i];
            for(int j = 1; j <= size; j++)
            {
                if(dAn[i][j - 1] > i) edges.push_back({i, dAn[i][j - 1]});
            }
        }

        OUT << n << " " << edges.size() << "\n";
        for(auto& a : edges)
        {
            OUT << a.first << " " << a.second << "\n";
        }
    }

    IN.close();
    OUT.close();
    return 0;
}
