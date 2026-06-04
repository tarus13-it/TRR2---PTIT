#include <iostream>
#include <fstream>
#include <vector>

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
        std::vector<std::vector<int>> matrix(n + 1, std::vector<int> (n + 1, 0));
        for(int k = 1; k <= n; k++)
        {
            int dAnSize = dAn[k].size();
            for(int l = 1; l <= dAnSize; l++)
            {
                matrix[k][dAn[k][l - 1]] = 1;
            }
        }
        OUT << n << "\n";
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                OUT << matrix[i][j];
                if(j < n) OUT << " ";
            }
            OUT << "\n";
        }
    }

    IN.close();
    OUT.close();
    return 0;
}
