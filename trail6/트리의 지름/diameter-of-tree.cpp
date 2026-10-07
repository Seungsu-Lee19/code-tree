#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int n;
vector<vector<pair<int, int>>> graph;
vector<int> visited;

void dfs(int cur){
    for(auto [next, value] : graph[cur]){
        if(visited[next] == -1){
            visited[next] = visited[cur] + value;

            dfs(next);
        }
    }
}

int main() {
    cin >> n;

    graph.resize(n + 1);

    int from, to, dist;
    for (int i = 0; i < n - 1; i++) {
        cin >> from >> to >> dist;
        graph[from].push_back({to, dist});
        graph[to].push_back({from, dist});
    }

    visited.assign(n + 1, -1);
    visited[1] = 0;
    dfs(1);

    int max_idx1 = max_element(visited.begin(), visited.end()) - visited.begin();
    visited.assign(n + 1, -1);
    visited[max_idx1] = 0;

    dfs(max_idx1);
    // int max_idx2 = max_element(visited.begin(), visited.end()) - visited.begin();

    cout << *max_element(visited.begin(), visited.end());


    return 0;
}