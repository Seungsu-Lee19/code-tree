#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<int>> graph;
vector<int> parent;

void dfs(int cur) {
    for (int next : graph[cur]) {
        // 이미 부모가 정해졌다면 방문한 노드
        if (parent[next] != 0)
            continue;

        parent[next] = cur;
        dfs(next);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    graph.resize(N + 1);
    parent.resize(N + 1, 0);

    // 트리는 N개의 노드라면 간선은 N-1개
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // 1번이 루트
    parent[1] = -1;
    dfs(1);

    // 2번 ~ N번 노드의 부모 출력
    for (int i = 2; i <= N; i++) {
        cout << parent[i] << '\n';
    }

    return 0;
}