#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int n;

vector<vector<pair<int, int>>> graph;
vector<int> visited;

void dfs(int cur, int removed){
    for(auto [next, value] : graph[cur]){
        if(next == removed) continue;

        if(visited[next] == -1){
            visited[next] = visited[cur] + value;
            dfs(next, removed);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    graph.resize(n);

    int from, to, weight;
    for (int i = 0; i < n - 1; i++) {
        cin >> from >> to >> weight;

        graph[from].push_back({to, weight});
        graph[to].push_back({from, weight});
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        for(auto [next, value]: graph[i]){
            visited.assign(n, -1);
            visited[i] = 0;   
            dfs(i, next);
            int max_idx = max_element(visited.begin(), visited.end()) - visited.begin();

            visited.assign(n, -1);
            visited[max_idx] = 0;   
            dfs(max_idx, next);

            int max_value1 = *max_element(visited.begin(), visited.end());

            ////////////////////////////////////////////////////////////////////////////////
            visited.assign(n, -1);
            visited[next] = 0;   
            dfs(next, i);
            max_idx = max_element(visited.begin(), visited.end()) - visited.begin();

            visited.assign(n, -1);
            visited[max_idx] = 0;   
            dfs(max_idx, i);

            int max_value2 = *max_element(visited.begin(), visited.end());

            ans = max(ans, max_value1 + max_value2 + value);
        }
    }

    cout << ans;


    return 0;
}