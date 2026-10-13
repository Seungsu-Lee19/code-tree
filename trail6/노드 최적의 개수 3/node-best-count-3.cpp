
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int n;
vector<vector<int>> graph;
vector<vector<int>> dp;

void dfs(int node, int parent) {
    // 0: 현재 노드에 물건을 놓음
    // 1: 자식이 현재 노드를 보호
    // 2: 부모가 현재 노드를 보호해야 함

    dp[node][0] = 1;
    dp[node][1] = INF;
    dp[node][2] = 0;

    int base = 0;
    int extra = INF;
    bool hasChild = false;

    for (int next : graph[node]) {
        if (next == parent) continue;

        dfs(next, node);

        hasChild = true;

        // 현재 노드를 선택한 경우
        dp[node][0] += min({
            dp[next][0],
            dp[next][1],
            dp[next][2]
        });

        // 현재 노드를 선택하지 않은 경우
        int best = min(dp[next][0], dp[next][1]);

        base += best;

        // 자식 중 하나는 반드시 선택해야 함
        extra = min(extra, dp[next][0] - best);
    }

    dp[node][2] = base;

    if (hasChild) {
        dp[node][1] = base + extra;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    graph.resize(n + 1);
    dp.resize(n + 1, vector<int>(3, INF));

    int a, b;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, 0);

    cout << min(dp[1][0], dp[1][1]) << '\n';

    return 0;
}
