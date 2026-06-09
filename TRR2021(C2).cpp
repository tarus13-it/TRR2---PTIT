#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <cstdio>

int n;
std::vector<std::vector<int>> adj;

int countComponents(int skip)
{
    std::vector<bool> visited(n + 1, false);
    visited[skip] = true;
    int components = {0};
    
    for(int i = 1; i <= n; i++)
    {
        if(visited[i]) continue;
        components++;
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
                    visited[w] = true;
                    st.push(w);
                }
            }
        }
    }
    return components;
}

int main()
{
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    std::cin >> n;
    adj.resize(n + 1, std::vector<int> (n + 1));
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++) std::cin >> adj[i][j];
    }
    
    int base = countComponents(0);
    
    std::vector<int> result;
    for(int i = 1; i <= n; i++)
    {
        if(countComponents(i) > base) result.push_back(i);
    }
    
    int rSize = result.size();
    std::cout << rSize << "\n";
    if(!result.empty())
    {
        for(int i = 0; i < rSize; i++)
        {
            std::cout << result[i];
            if(i < rSize - 1) std::cout << " ";
        }
        std::cout << "\n";
    }
    
    return 0;
}