#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <climits>

using namespace std;

int n, d;

vector<vector<pair<int, int>>> graph;
vector<pair<int, int>> visited;

void find_max_node(int cur){
    for(auto [next, value]: graph[cur]){
        auto [cnt, dist] = visited[next];

        if(cnt == -1 && dist == -1){
            visited[next] = {visited[cur].first + 1, visited[cur].second - value};

            find_max_node(next);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> d;

    graph.resize(n + 1);

    int from, to, length;
    for (int i = 0; i < n - 1; i++) {
        cin >> from >> to >> length;

        graph[from].push_back({to, length});
        graph[to].push_back({from, length});
    }

    visited.assign(n + 1, {-1, -1});
    visited[1] = make_pair(0, 0);
    find_max_node(1);

    int max_idx = max_element(visited.begin(), visited.end()) - visited.begin();

    visited.assign(n + 1, {-1, -1});
    visited[max_idx] = make_pair(0, 0);
    find_max_node(max_idx);

    auto [cnt, dist] = *max_element(visited.begin(), visited.end());

    cout << (-dist + d - 1) / d;


    return 0;
}