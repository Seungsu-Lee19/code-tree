#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> graph;
vector<int> visited;
int ans = -1;

void dfs(int cur){
    visited[cur] = 1;
    ans++;

    // cout << cur << endl;

    for(int next: graph[cur]){
        if(visited[next] == 1) continue;

        dfs(next);
    }
}

int main() {
    cin >> n >> m;

    int from, to;
    graph.resize(n + 1);
    visited.resize(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> from >> to;

        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    // Please write your code here.
    dfs(1);
    cout << ans;

    return 0;
}
