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
    std::vector<std::vector<int>> neighbor(n + 1);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            IN >> a[i][j];
            if(a[i][j] == 1) neighbor[i].push_back(j);
        }
    }

    if(t == 1)
    {
        for(int i = 1; i <= n; i++)
        {
            int bac{0};
            for(int j = 1; j <= n; j++)
            {
                bac += a[i][j];
            }
            OUT << bac;
            if(i < n) OUT << " ";
        }
        OUT << "\n";
    }

    else {
        OUT << n << " ";
        for(int i = 1; i <= n; i++)
        {
            OUT << neighbor[i].size() << " ";
            for(auto& x : neighbor[i])
            {
                OUT << x << " ";
            }
            OUT << "\n";
        }
    }
    IN.close();
    OUT.close();
    return 0;
}
