#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int values[10001];

vector<vector<int>> graph;
vector<bool> visited;
vector<vector<int>> dp;
// dp[x][0] = x노드를 선택x
// dp[x][1] = x노드를 선택

void dfs(int node, int parent){
    for(int next: graph[node]){
        if(!visited[next]){
            visited[next] = true;
            dfs(next, node);
        }
    }

    dp[node][1] = values[node];
    for(int next: graph[node]){
        if(next == parent) continue;

        dp[node][1] += dp[next][0];
        dp[node][0] += max(dp[next][0], dp[next][1]);
    }
}

int main() {
    cin >> n;

    graph.resize(n + 1);
    visited.resize(n + 1);
    dp.resize(n + 1, vector<int>(2));

    for (int i = 1; i <= n; i++) {
        cin >> values[i];
    }

    int from, to;
    for (int i = 0; i < n - 1; i++) {
        cin >> from >> to;

        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    visited[1] = true;
    dfs(1, 1);

    cout << max(dp[1][0], dp[1][1]);

    return 0;
}