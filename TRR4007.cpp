#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

int n, m;

struct Edge { int u, v, w; };

// DSU
int parent[105], rank_[105];

int find(int x)
{
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

bool unite(int x, int y)
{
    int px = find(x), py = find(y);
    if (px == py) return false;
    if (rank_[px] < rank_[py]) std::swap(px, py);
    parent[py] = px;
    if (rank_[px] == rank_[py]) rank_[px]++;
    return true;
}

int main()
{
    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);

    std::cin >> n >> m;

    std::vector<Edge> edges(m);
    for (int i = 0; i < m; i++)
        std::cin >> edges[i].u >> edges[i].v >> edges[i].w;

    // sắp xếp cạnh theo trọng số tăng dần
    std::sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b){
        return a.w < b.w;
    });

    // khởi tạo DSU
    for (int i = 1; i <= n; i++) { parent[i] = i; rank_[i] = 0; }

    std::vector<Edge> result;
    int total = 0;

    for (int i = 0; i < m; i++)
    {
        if (unite(edges[i].u, edges[i].v))
        {
            result.push_back(edges[i]);
            total += edges[i].w;
        }
        if ((int)result.size() == n - 1) break;
    }

    if ((int)result.size() != n - 1)
        std::cout << 0 << "\n";
    else
    {
        std::cout << total << "\n";
        for (int i = 0; i < (int)result.size(); i++)
            std::cout << result[i].u << " " << result[i].v << " " << result[i].w << "\n";
    }
    return 0;
}
