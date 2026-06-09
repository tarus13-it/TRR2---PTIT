#include <iostream>
#include <vector>
#include <cstdio>
#include <stack>

int n;
std::vector<std::vector<int>> adj;

void dfs(int start, std::vector<std::vector<int>>& graph, std::vector<bool>& visited)
{
    std::stack<int> st;
    visited[start] = true;
    st.push(start);
    while (!st.empty())
    {
        int current = st.top();
        st.pop();
        for (int w = 1; w <= n; w++)
        {
            if (graph[current][w] == 1 && !visited[w])
            {
                visited[w] = true;
                st.push(w);
            }
        }
    }
}

bool allVisited(std::vector<bool>& visited)
{
    for (int i = 1; i <= n; i++)
        if (!visited[i]) return false;
    return true;
}

int main()
{
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);

    std::cin >> n;
    adj.resize(n + 1, std::vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            std::cin >> adj[i][j];

    // Xây đồ thị vô hướng hóa
    std::vector<std::vector<int>> undirected(n + 1, std::vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (adj[i][j] == 1) undirected[i][j] = undirected[j][i] = 1;

    // Kiểm tra liên thông mạnh: DFS từ mọi đỉnh trên đồ thị có hướng
    bool strong = true;
    for (int i = 1; i <= n; i++)
    {
        std::vector<bool> visited(n + 1, false);
        dfs(i, adj, visited);
        if (!allVisited(visited)) { strong = false; break; }
    }

    if (strong)
    {
        std::cout << 1 << "\n";
    }
    else
    {
        // Kiểm tra liên thông yếu: DFS từ đỉnh 1 trên đồ thị vô hướng hóa
        std::vector<bool> visited(n + 1, false);
        dfs(1, undirected, visited);
        if (allVisited(visited)) std::cout << 2 << "\n";
        else std::cout << 0 << "\n";
    }

    return 0;
}
