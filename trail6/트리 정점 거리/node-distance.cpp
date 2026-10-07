#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int n, m;

vector<vector<pair<int, int>>> graph;

int bfs(int start, int end){
    vector<int> visited(n + 1, -1);
    queue<int> q;

    q.push(start);
    visited[start] = 0;

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        if(cur == end) return visited[cur];
        
        for(auto [next, value]: graph[cur]){
            if(visited[next] == -1){
                visited[next] = visited[cur] + value;
                q.push(next);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    graph.resize(n + 1);

    int from, to, weight;
    for (int i = 0; i < n - 1; i++) {
        cin >> from >> to >> weight;
        
        graph[from].push_back({to, weight});
        graph[to].push_back({from, weight});
    }

    int query_from, query_to;
    for (int i = 0; i < m; i++) {
        cin >> query_from >> query_to;

        if(query_from == query_to){
            cout << "0\n";
            continue;
        }

        cout << bfs(query_from, query_to) << "\n";
    }

    // Please write your code here.

    return 0;
}