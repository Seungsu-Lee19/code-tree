#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int l[1001], m[1001], r[1001];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> m[i] >> r[i];
    }

    // Please write your code here.
    // dp[i][j]
    // i <= n, i번째 방까지
    // 0 <= j <= 3, 왼쪽, 가운데, 오른쪽 방
    // dp[i][j] = max(dp[i - 1][k] + lmr[k])

    vector<vector<int>> dp(
        n + 1,
        vector<int>(3)
    );

    dp[1][0] = l[1];
    dp[1][1] = m[1];
    dp[1][2] = r[1];

    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                if(j == k) continue;

                if(j == 0) dp[i][j] = max(dp[i][j], dp[i - 1][k] + l[i]);
                else if(j == 1) dp[i][j] = max(dp[i][j], dp[i - 1][k] + m[i]);
                else if(j == 2) dp[i][j] = max(dp[i][j], dp[i - 1][k] + r[i]);
            }
        }
    }

    int ans = 0;

    for(int i = 0; i < 3; i++){
        ans = max(ans, dp[n][i]);
    }

    cout << ans;


    return 0;
}
