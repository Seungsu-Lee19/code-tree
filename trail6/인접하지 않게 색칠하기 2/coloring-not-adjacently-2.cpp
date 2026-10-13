
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int NEG = -1000000000;

int n, k;

vector<vector<int>> graph;
vector<int> value;
vector<vector<vector<int>>> dp;
vector<int> cnt;

void dfs(int node, int parent) {
    // dp[node][개수][현재 노드 선택 여부]
    dp[node][0][0] = 0;
    dp[node][1][1] = value[node];

    cnt[node] = 1;

    for (int next : graph[node]) {
        if (next == parent) continue;

        dfs(next, node);

        vector<vector<int>> temp(k + 1, vector<int>(2, NEG));

        for (int i = 0; i <= min(k, cnt[node]); i++) {
            for (int j = 0; j <= min(k - i, cnt[next]); j++) {

                // 현재 노드를 선택하지 않은 경우
                if (dp[node][i][0] != NEG) {
                    int childBest = max(dp[next][j][0], dp[next][j][1]);

                    if (childBest != NEG) {
                        temp[i + j][0] = max(
                            temp[i + j][0],
                            dp[node][i][0] + childBest
                        );
                    }
                }

                // 현재 노드를 선택한 경우
                if (dp[node][i][1] != NEG &&
                    dp[next][j][0] != NEG) {

                    temp[i + j][1] = max(
                        temp[i + j][1],
                        dp[node][i][1] + dp[next][j][0]
                    );
                }
            }
        }

        for (int i = 0; i <= k; i++) {
            dp[node][i][0] = temp[i][0];
            dp[node][i][1] = temp[i][1];
        }

        cnt[node] += cnt[next];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    graph.resize(n + 1);
    value.resize(n + 1);
    cnt.resize(n + 1);

    dp.resize(n + 1,
        vector<vector<int>>(11, vector<int>(2, NEG)));

    int a, b;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        cin >> value[i];
    }

    cin >> k;

    dfs(1, 0);

    int ans = 0;

    for (int i = 0; i <= k; i++) {
        ans = max(ans, max(dp[1][i][0], dp[1][i][1]));
    }

    cout << ans << '\n';

    return 0;
}
