#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int n, r, q;

vector<vector<int>> graph;
vector<int> dp;
vector<bool> visited;

void dfs(int node){
    dp[node] = 1;

    for(int next: graph[node]){
        if(!visited[next]){
            visited[next] = true;
            dfs(next);
            dp[node] += dp[next];
        }
    }

}

int main() {
    cin >> n >> r >> q;

    graph.resize(n + 1);
    dp.resize(n + 1);
    visited.resize(n + 1);

    int from, to;
    for (int i = 0; i < n - 1; i++) {
        cin >> from >> to;

        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    visited[r] = true;
    dfs(r);

    int U;
    for (int i = 0; i < q; i++) {
        cin >> U;
        cout << dp[U] << "\n";
    }

    // for(int i = 1; i <= n; i++){
    //     cout << dp[i] << " ";
    // }

    // Please write your code here.

    return 0;
}