#include <iostream>
#include <vector>

using namespace std;

int n;
int values[10001];

vector<vector<int>> graph;
vector<bool> visited;
vector<int> dp;

int ans = 0;

void dfs(int node, int prev){
    for(int next: graph[node]){
        if(!visited[next]){
            visited[next] = true;
            dfs(next, node);
        }
    }

    // cout << node << " => " << values[node] << endl;
    if(node == 1) return;

    if(values[node] > 1){
        ans += (values[node] - 1);
        values[prev] += (values[node] - 1);
    }
    else if(values[node] < 1){
        ans += (-values[node] + 1);
        values[prev] -= (-values[node] + 1);
    }
}

int main() {
    cin >> n;

    graph.resize(n + 1);
    visited.resize(n + 1);
    dp.resize(n + 1);

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
    visited[0] = true;
    dfs(1, 0);

    cout << ans;

    return 0;
}