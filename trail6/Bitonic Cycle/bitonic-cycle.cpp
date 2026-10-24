#include <iostream>
#include <vector>
#include <utility>
#include <climits>
#include <algorithm>

using namespace std;

int n;

// long long calc_dist

int main() {
    cin >> n;

    vector<pair<int, int>> grid;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        grid.push_back({x, y});
    }

    sort(grid.begin(), grid.end());

    // Please write your code here.


    vector<vector<long long>> dp(n, vector<long long>(n, 1e16));
    dp[0][0] = 0;
    for(int i = 0; i < n; i++){
        auto [x1, y1] = grid[i];

        for(int j = 0; j < n; j++){
            int next = max(i, j) + 1;

            if(next >= n) continue;

            auto [x2, y2] = grid[j];
            auto [x3, y3] = grid[next];

            long long dist1 = (x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2);
            long long dist2 = (x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3);

            dp[next][j] = min(dp[next][j], dp[i][j] + dist2);
            dp[i][next] = min(dp[i][next], dp[i][j] + dist1);
        }
    }

    long long ans = 1e16;
    for(int i = 0; i < n; i++){
        // cout << dp[i][n - 1] << " " << dp[n - 1][i] << endl;
        auto [x1, y1] = grid[i];
        auto [x2, y2] = grid[n - 1];
        long long dist1 = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1- y2);
        ans = min(ans, dp[i][n - 1] + dist1);
    }
    cout << ans;

    return 0;
}