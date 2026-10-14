#include <iostream>
#include <vector>

using namespace std;

int n, m;

vector<int> items;
vector<vector<int>> graph, dp;

void dfs(int node, int parent){
    for(int next: graph[node]){
        if(next == parent) continue;

        dfs(next, node);
    }

    dp[node][1] = 1 - items[node];

    for(int next: graph[node]){
        if(next == parent) continue;

        dp[node][0] += dp[next][1];
        dp[node][1] += min(dp[next][0], dp[next][1]);
    }
}

int main() {
    cin >> n >> m;

    graph.resize(n + 1);
    items.resize(n + 1);
    dp.resize(n + 1, vector<int>(2));

    int from, to;
    for (int i = 0; i < n - 1; i++) {
        cin >> from >> to;
        
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    int item;
    for (int i = 0; i < m; i++) {
        cin >> item;
        items[item] = 1;
    }

    dfs(1, 1);

    cout << min(dp[1][1], dp[1][0]);

    return 0;
}