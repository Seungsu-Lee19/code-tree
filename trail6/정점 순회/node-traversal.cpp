#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, s, d;

vector<vector<int>> graph;
vector<bool> visited;
vector<int> dp;

int ans = 0;

void dfs(int node){
    dp[node] = 0;

    for(int next: graph[node]){
        if(!visited[next]){
            visited[next] = true;
            dfs(next);

            dp[node] = max(dp[node], dp[next] + 1);

            if(dp[next] >= d) ans += 2;
        }
    }
}

int main() {
    cin >> n >> s >> d;

    graph.resize(n + 1);
    visited.resize(n + 1);
    dp.resize(n + 1);

    int from, to;
    for (int i = 0; i < n - 1; i++) {
        cin >> from >> to;

        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    visited[s] = true;
    dfs(s);
    
    cout << ans;
    // Please write your code here.

    return 0;
}