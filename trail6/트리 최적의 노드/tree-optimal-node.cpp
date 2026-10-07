#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n;

vector<vector<int>> graph;

void dfs(int cur, vector<int>& visited){
    for(auto next: graph[cur]){
        if(visited[next] == -1){
            visited[next] = visited[cur] + 1;
            dfs(next, visited);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    graph.resize(n + 1);

    int from, to;
    for (int i = 0; i < n - 1; i++) {
        cin >> from >> to;

        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    vector<int> visitedA(n + 1, -1);
    visitedA[from] = 0;
    dfs(from, visitedA);

    int max_idx = max_element(visitedA.begin(), visitedA.end()) - visitedA.begin();
    visitedA.assign(n + 1, -1);
    visitedA[max_idx] = 0;
    dfs(max_idx, visitedA);

    max_idx = max_element(visitedA.begin(), visitedA.end()) - visitedA.begin();
    vector<int> visitedB(n + 1, -1);
    visitedB[max_idx] = 0;
    dfs(max_idx, visitedB);

    int ans = INT_MAX;
    for(int i = 1; i <= n; i++){
        ans = min(ans, max(visitedA[i], visitedB[i]));
    }
    

    cout << ans;


    return 0;
}