#include <iostream>
#include <vector>

using namespace std;

int n, m;

vector<vector<int>> graph;
vector<bool> visited;

int nodeCnt;
long long edgeCnt;

void dfs(int cur){
    visited[cur] = true;

    nodeCnt++;
    edgeCnt += graph[cur].size();

    for(int next : graph[cur]){
        if(!visited[next]){
            dfs(next);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    graph.resize(n + 1);
    visited.resize(n + 1, false);

    int from, to;

    for(int i = 0; i < m; i++){
        cin >> from >> to;

        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    int ans = 0;

    for(int i = 1; i <= n; i++){

        // 이미 다른 연결 요소의 DFS에서 방문함
        if(visited[i]) continue;

        // 새로운 연결 요소 시작
        nodeCnt = 0;
        edgeCnt = 0;

        dfs(i);

        // 무방향 그래프라 모든 간선을 2번씩 셌음
        edgeCnt /= 2;

        // 연결 요소이므로
        // 간선 = 정점 - 1 이면 트리
        if(edgeCnt == nodeCnt - 1){
            ans++;
        }
    }

    cout << ans;

    return 0;
}