#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>
#include <cstdio>

int n;
std::vector<std::vector<int>> adj;

void dfs(int u, std::vector<bool>& visited)
{
    visited[u] = true;
    for (int w = 1; w <= n; w++)
        if (adj[u][w] && !visited[w])
            dfs(w, visited);
}

bool isConnected()
{
    int start = -1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (adj[i][j]) { start = i; break; }
    if (start == -1) return true;

    std::vector<bool> visited(n + 1, false);
    dfs(start, visited);
    for (int i = 1; i <= n; i++)
    {
        bool hasDeg = false;
        for (int j = 1; j <= n; j++) if (adj[i][j]) { hasDeg = true; break; }
        if (hasDeg && !visited[i]) return false;
    }
    return true;
}

std::vector<int> hierholzer(int u)
{
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
            a[v].erase(w);
            a[w].erase(v);
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
        if (!isConnected()) { std::cout << 0 << "\n"; return 0; }
        int oddCount = 0;
        for (int i = 1; i <= n; i++)
        {
            int deg = 0;
            for (int j = 1; j <= n; j++) deg += adj[i][j];
            if (deg % 2 != 0) oddCount++;
        }
        if (oddCount == 0)      std::cout << 1 << "\n";
        else if (oddCount == 2) std::cout << 2 << "\n";
        else                    std::cout << 0 << "\n";
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
