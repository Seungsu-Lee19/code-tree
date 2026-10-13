
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n;

vector<int> value;
vector<vector<int>> graph;
vector<int> dp;

int ans = INT_MIN;

void dfs(int node, int prev) {
    int max1 = 0;
    int max2 = 0;

    for (int next : graph[node]) {
        if (next == prev) continue;

        dfs(next, node);

        int v = max(0, dp[next]);

        if (v > max1) {
            max2 = max1;
            max1 = v;
        }
        else if (v > max2) {
            max2 = v;
        }
    }

    // 현재 노드에서 아래로 내려가는 최대 경로 합
    dp[node] = value[node] + max1;

    // 현재 노드를 중간에 두고 양쪽 경로 연결
    ans = max(ans, value[node] + max1 + max2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    graph.resize(n + 1);
    value.resize(n + 1);
    dp.resize(n + 1);

    int from, to;
    for (int i = 0; i < n - 1; i++) {
        cin >> from >> to;

        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    for (int i = 1; i <= n; i++) {
        cin >> value[i];
    }

    dfs(1, 0);

    cout << ans << '\n';

    return 0;
}
