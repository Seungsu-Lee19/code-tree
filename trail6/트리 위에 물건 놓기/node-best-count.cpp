#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

vector<vector<int>> graph;
vector<vector<int>> dp;
vector<bool> visited;

void dfs(int node){
    for(int next: graph[node]){
        if(visited[next] == false){
            visited[next] = true;
            dfs(next);
        }
    }

    int child_value = 0;
    for(int next: graph[node]){
        dp[node][0] += dp[next][1];
        child_value += min(dp[next][0], dp[next][1]); 
    }
    dp[node][1] = 1 + child_value;
}

int main() {
    cin >> n;

    graph.resize(n + 1);
    dp.resize(n + 1, vector<int>(2));
    visited.resize(n + 1);

    int from, to;
    for (int i = 0; i < n - 1; i++) {
        cin >> from >> to;

        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    visited[1] = true;
    dfs(1);
    cout << min(dp[1][0], dp[1][1]);

    return 0;
}