#include <iostream>
#include <vector>
#include <fstream>

int main()
{
    std::ifstream IN("DT.INP");
    std::ofstream OUT("DT.OUT");

    int t, n;
    IN >> t;
    IN >> n;

    std::vector<std::vector<int>> a(n + 1, std::vector<int> (n + 1));
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++) IN >> a[i][j];
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
        std::vector<std::pair<int, int>> b;
        for(int i = 1; i <= n; i++)
        {
            for(int j = i + 1; j <= n; j++)
            {
                if(a[i][j] == 1) b.push_back({i, j});
            }
        }

        int edge = b.size();
        OUT << n << " " << edge << "\n";
        for(auto& x : b)
        {
            OUT << x.first << " " << x.second << "\n";
        }
    }
    IN.close();
    OUT.close();
    return 0;
}
