#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int points[2001];

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> points[i];
    }

    vector<bool> valid(n + 1, false);
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        valid[x] = true;
    }

    // Please write your code here.
    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, INT_MAX));
    dp[0][0] = 0;

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            int next = max(i, j) + 1;

            if(next > n) continue;
            if(dp[i][j] == INT_MAX) continue;

            long long cost1 = (i == 0)? 0 : abs(points[i] - points[next]);
            long long cost2 = (j == 0)? 0 : abs(points[j] - points[next]);

            dp[next][j] = min(dp[next][j], dp[i][j] + cost1);
            if(!valid[next]) dp[i][next] = min(dp[i][next], dp[i][j] + cost2);
        }
    }

    // for(int i = 0; i <= n; i++){
    //     for(int j = 0; j <= n; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    long long ans = INT_MAX;
    for(int i = 0; i <= n; i++){
        ans = min(ans, min(dp[n][i], dp[i][n]));
    }

    cout << ans;

    return 0;
}
