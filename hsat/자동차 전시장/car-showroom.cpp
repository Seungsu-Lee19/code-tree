#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

int n, m, K;
vector<vector<int>> edges;

vector<int> bfs(int sx){
    vector<int> visited(n, -1);
    queue<int> q;

    visited[sx] = 0;
    q.push(sx);

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(int next: edges[cur]){
            if(visited[next] == -1){
                visited[next] = visited[cur] + 1;
                q.push(next);
            }
        }
    }

    return visited;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> K;

    edges.resize(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        edges[x].push_back(y);
    }

    vector<vector<int>> time(K);
    for (int i = 0; i < K; i++) {
        int start_point;
        cin >> start_point;
        start_point--;

        time[i] = bfs(start_point);
    }

    // Please write your code here.

    // time[k][i] => k start_point에서 i노드까지 가는 최단 거리
    // 모든 k에 대해서 특정 노드 i까지의 거리의 최대값의 최소값을 구하라.

    int ans = INT_MAX;
    for(int i = 0; i < n; i++){
        int max_dist = -1;
        for(int k = 0; k < K; k++){
            if(time[k][i] == -1) {
                max_dist = -1;
                break;
            }

            max_dist = max(max_dist, time[k][i]);
        }

        // cout << i << " " << max_dist << endl;

        if(max_dist != -1) ans = min(ans, max_dist);
    }

    if(ans == INT_MAX) cout << -1;
    else cout << ans;

    return 0;
}
