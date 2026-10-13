#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

vector<int> values;
vector<vector<int>> graph;
vector<vector<int>> dp;
vector<int> ans;

void dfs(int node, int parent){
    for(int next: graph[node]){
        if(next != parent){
            dfs(next, node);
        }
    }

    dp[node][1] = values[node];
    for(int child: graph[node]){
        if(child == parent) continue;

        dp[node][1] += dp[child][0];
        dp[node][0] += max(dp[child][0], dp[child][1]);
    }
}

void trace(int node, int parent, bool parentSeleted){
    bool isSelected = false;

    if(!parentSeleted && dp[node][1] > dp[node][0]){
        isSelected = true;
        ans.push_back(node);
    }

    for(int next: graph[node]){
        if(next != parent){
            trace(next, node, isSelected);
        }
    }
}

int main() {
    cin >> n;

    graph.resize(n + 1);
    values.resize(n + 1);
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

    // Please write your code here.
    dfs(1, 1);
    trace(1, 1, false);

    sort(ans.begin(), ans.end());

    cout << max(dp[1][0], dp[1][1]) << "\n";
    for(int x: ans) cout << x << " ";

    return 0;
}