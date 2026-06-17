#include <iostream>
#include <vector>
#include <cstdio>

const int INF = 10000;
int n;
int dist[105][105];
int next_[105][105];  // next_[i][j] = đỉnh tiếp theo trên đường đi từ i đến j

int main()
{
    freopen("DN.INP", "r", stdin);
    freopen("DN.OUT", "w", stdout);

    std::cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            std::cin >> dist[i][j];
            if (i != j && dist[i][j] < INF)
                next_[i][j] = j;
            else
                next_[i][j] = -1;
        }

    // Floyd-Warshall
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (dist[i][k] < INF && dist[k][j] < INF)
                    if (dist[i][k] + dist[k][j] < dist[i][j])
                    {
                        dist[i][j] = dist[i][k] + dist[k][j];
                        next_[i][j] = next_[i][k];
                    }

    // tìm cặp (u,v) có đường đi ngắn nhất lớn nhất
    int maxDist = -1, bestU = -1, bestV = -1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i != j && dist[i][j] < INF)
                if (dist[i][j] > maxDist)
                {
                    maxDist = dist[i][j];
                    bestU = i;
                    bestV = j;
                }

    if (bestU == -1)
    {
        std::cout << 0 << "\n";
    }
    else
    {
        std::cout << bestU << " " << bestV << " " << maxDist << "\n";

        // truy vết đường đi qua next_[]
        std::vector<int> path;
        int cur = bestU;
        while (cur != bestV)
        {
            path.push_back(cur);
            cur = next_[cur][bestV];
        }
        path.push_back(bestV);

        for (int i = 0; i < (int)path.size(); i++)
        {
            if (i > 0) std::cout << " ";
            std::cout << path[i];
        }
        std::cout << "\n";
    }
    return 0;
}
