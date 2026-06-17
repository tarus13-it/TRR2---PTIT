#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>
#include <cstdio>

int n;
std::vector<std::vector<int>> adj;

void dfs(int u, std::vector<std::vector<int>>& graph, std::vector<bool>& visited)
{
    visited[u] = true;
    for (int w = 1; w <= n; w++)
        if (graph[u][w] && !visited[w])
        dfs(w, graph, visited);
}

bool isWeaklyConnected()
{
    // vô hướng hóa
    std::vector<std::vector<int>> undirected(n + 1, std::vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (adj[i][j]) undirected[i][j] = undirected[j][i] = 1;

    int start = -1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (undirected[i][j]) { start = i; break; }
    if (start == -1) return true;

    std::vector<bool> visited(n + 1, false);
    dfs(start, undirected, visited);
    for (int i = 1; i <= n; i++)
    {
        bool hasDeg = false;
        for (int j = 1; j <= n; j++) if (undirected[i][j]) { hasDeg = true; break; }
        if (hasDeg && !visited[i]) return false;
    }
    return true;
}

std::vector<int> hierholzer(int u)
{
    // danh sách kề có hướng
    std::vector<std::set<int>> a(n + 1);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (adj[i][j]) a[i].insert(j);

    std::stack<int> st;
    std::vector<int> circuit;
    st.push(u);
    while (!st.empty())
    {
        int v = st.top();
        if (!a[v].empty())
        {
            int w = *a[v].begin();
            a[v].erase(w);       // chỉ xóa một chiều
            st.push(w);
        }
        else
        {
            circuit.push_back(v);
            st.pop();
        }
    }
    std::reverse(circuit.begin(), circuit.end());
    return circuit;
}

int main()
{
    freopen("CT.INP", "r", stdin);
    freopen("CT.OUT", "w", stdout);

    int t;
    std::cin >> t;

    int u = 1;
    if (t == 1) std::cin >> n;
    else        std::cin >> n >> u;

    adj.resize(n + 1, std::vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            std::cin >> adj[i][j];

    if (t == 1)
    {
        if (!isWeaklyConnected()) { std::cout << 0 << "\n"; return 0; }

        std::vector<int> inDeg(n + 1, 0), outDeg(n + 1, 0);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (adj[i][j]) { outDeg[i]++; inDeg[j]++; }

        // Euler: tất cả inDeg == outDeg
        bool euler = true;
        for (int i = 1; i <= n; i++)
            if (inDeg[i] != outDeg[i]) { euler = false; break; }
        if (euler) { std::cout << 1 << "\n"; return 0; }

        // nửa Euler: đúng 1 đỉnh out-in=1, đúng 1 đỉnh in-out=1, còn lại bằng nhau
        int startCount = 0, endCount = 0;
        bool semiEuler = true;
        for (int i = 1; i <= n; i++)
        {
            int diff = outDeg[i] - inDeg[i];
            if (diff == 1) startCount++;
            else if (diff == -1) endCount++;
            else if (diff != 0) { semiEuler = false; break; }
        }
        if (semiEuler && startCount == 1 && endCount == 1)
            std::cout << 2 << "\n";
        else
            std::cout << 0 << "\n";
    }
    else
    {
        std::vector<int> circuit = hierholzer(u);
        for (int i = 0; i < (int)circuit.size(); i++)
        {
            if (i > 0) std::cout << " ";
            std::cout << circuit[i];
        }
        std::cout << "\n";
    }
    return 0;
}
