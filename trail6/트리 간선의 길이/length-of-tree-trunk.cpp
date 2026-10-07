#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

vector<vector<pair<int, int>>> graph(10001);
vector<int> visited(10001, -1);

void dfs(int cur){
    for(auto [next, value]: graph[cur]){
        if(visited[next] == -1){
            visited[next] = visited[cur] + value;
            dfs(next);
        }
    }
}

int main() {
    cin >> n;


    int from, to, weight;
    for (int i = 0; i < n - 1; i++) {
        cin >> from >> to >> weight;

        graph[from].push_back({to, weight});
        graph[to].push_back({from, weight});
    }

    visited[from] = 0;
    dfs(from);
    int max_idx = max_element(visited.begin(), visited.end()) - visited.begin();

    visited.assign(10001, -1);
    visited[max_idx] = 0;
    dfs(max_idx);

    cout << *max_element(visited.begin(), visited.end());

    return 0;
}