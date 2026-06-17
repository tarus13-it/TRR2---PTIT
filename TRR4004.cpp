#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

const int INF = 1e9;
int n, s;
int a[105][105];
std::vector<std::pair<int,int>> adj[105];

struct Edge { int u, v, w; };

int main()
{
    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);

    std::cin >> n >> s;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            int val; std::cin >> val;
            a[i][j] = val;
            if (val > 0)
            {
                adj[i].push_back({j, val});
                adj[j].push_back({i, val});
            }
        }

    std::vector<bool> inMST(n + 1, false);
    std::vector<Edge> edges;
    inMST[s] = true;
    int total = 0;

    while ((int)edges.size() < n - 1)
    {
        int minW = INF, x = -1, y = -1;
        for (int i = 1; i <= n; i++)
        {
            if (!inMST[i]) continue;
            for (auto& p : adj[i])
            {
                int j = p.first, w = p.second;
                if (!inMST[j] && w < minW)
                {
                    minW = w;
                    x = i; y = j;
                }
            }
        }

        if (x == -1) break;  // không liên thông

        Edge e;
        e.u = std::min(x, y);
        e.v = std::max(x, y);
        e.w = minW;
        edges.push_back(e);
        total += minW;
        inMST[y] = true;
    }

    if ((int)edges.size() != n - 1)
        std::cout << 0 << "\n";
    else
    {
        std::cout << total << "\n";
        for (int i = 0; i < (int)edges.size(); i++)
            std::cout << edges[i].u << " " << edges[i].v << " " << edges[i].w << "\n";
    }
    return 0;
}
