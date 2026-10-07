#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int n;

vector<vector<pair<int, int>>> graph(100001);
vector<int> visited;

void dfs(int cur){
    for(auto [next, value]: graph[cur]){
        if(visited[next] == -1){
            visited[next] = visited[cur] + value;
            dfs(next);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    int from, to, weight;
    for (int i = 0; i < n - 1; i++) {
        cin >> from >> to >> weight;

        graph[from].push_back({to, weight});
        graph[to].push_back({from, weight});
    }

    visited.assign(100001, -1);
    visited[from] = 0;
    dfs(from);
    
    int max_idxA = max_element(visited.begin(), visited.end()) - visited.begin();
    
    visited.assign(100001, -1);
    visited[max_idxA] = 0;
    dfs(max_idxA);

    vector<int> distA = visited;
    int max_idxB = max_element(visited.begin(), visited.end()) - visited.begin();
    
    visited.assign(100001, -1);
    visited[max_idxB] = 0;
    dfs(max_idxB);

    vector<int> distB = visited;

    distA[max_idxB] = 0;
    distB[max_idxA] = 0;

    cout << max(*max_element(distA.begin(), distA.end()), *max_element(distB.begin(), distB.end()));



    return 0;
}