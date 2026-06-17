#include <iostream>
#include <stack>
#include <cstdio>
#include <vector>

int n;
std::vector<std::vector<int>> adj;
std::vector<std::pair<int, int>> edges;

int countComponents(int a, int b)
{
    std::vector<bool> visited(n + 1, false);
    int count = {0};
    
    for(int i = 1; i <= n; i++)
    {
        if(visited[i]) continue;
        count++;
        std::stack<int> st;
        visited[i] = true;
        st.push(i);
        while(!st.empty())
        {
            int u = st.top();
            st.pop();
            for(int w = n; w >= 1; w--)
            {
                if(adj[u][w] == 1 && !visited[w])
                {
                    if(u == a && w == b) continue;
                    else
                    {
                        visited[w] = true;
                        st.push(w);
                    }
                }
            }
        }
    }


    return count;
}

int main()
{
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    std::cin >> n;
    adj.resize(n + 1, std::vector<int> (n + 1));
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            std::cin >> adj[i][j];
            if(adj[i][j] == 1 && i < j) edges.push_back({i, j});
        }
    }

    int base = countComponents(0, 0);
    std::vector<std::pair<int, int>> result;
    int eSize = edges.size();
    for(int i = 0; i < eSize; i++)
    {
        if(countComponents(edges[i].first, edges[i].second) > base) 
            result.push_back({edges[i].first, edges[i].second});
    }

    int rSize = result.size();
    std::cout << rSize << "\n";
    for(int i = 0; i < rSize; i++)
    {
        std::cout << result[i].first << " " << result[i].second << "\n";
    }

    return 0;
}
