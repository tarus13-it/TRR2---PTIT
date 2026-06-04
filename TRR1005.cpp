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
        std::vector<std::vector<int>> degree_and_neighbor(n + 1);

        for(int i = 1; i <= m; i++)
        {
            degree_and_neighbor[edges[i].first].push_back(edges[i].second);
            degree_and_neighbor[edges[i].second].push_back(edges[i].first);
        }

        OUT << n << "\n";
        for(int j = 1; j <= n; j++)
        {
            int dneSize = degree_and_neighbor[j].size();
            OUT << dneSize << " ";
            for(int k = 0; k < dneSize; k++)
            {
                OUT << degree_and_neighbor[j][k];
                if(k < dneSize - 1) OUT << " ";
            }
            OUT << "\n";
        }
    }

    IN.close();
    OUT.close();
    return 0;
}
