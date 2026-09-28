#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

const long long MOD = 1000000007;

int main() {
    cin >> n;

    // Please write your code here.

    // dp[i][j]
    // i 자릿 수
    // j 마지막 수
    // dp[i][j] = max(dp[i - 1][j + 1], dp[i - 1][j - 1]) + 1;

    vector<vector<long long>> dp(
        n + 1,
        vector<long long>(10)
    );

    for(int i = 1; i <= 9; i++){
        dp[1][i] = 1;
    }

    for(int i = 2; i <= n; i++){
        for(int j = 0; j < 10; j++){
            if(j == 0) dp[i][j] = dp[i - 1][1];
            else if(j == 9) dp[i][j] = dp[i - 1][8];
            else dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
        }
    }

    int ans = 0;
    for(int i = 0; i < 10; i++){
        ans = (ans + dp[n][i]) % MOD;
    }

    cout << ans;

    return 0;
}
