#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;

const long long MOD = 1000000007;

int main() {
    cin >> n;

    // Please write your code here.

    // dp[i][t][b] => i일 까지 t는 몇번 받았고, b가 몇번 연속됬냐
    // dp[i][t][0] += dp[i - 1][t][b] => g를 받은 경우 (모든 t, 모든 b에 대해)
    // dp[i][t][0] += dp[i - 1][t - 1][b] => t를 받은 경우 (모든 b에 대해)
    // dp[i][t][b] += dp[i - 1][t][b - 1] => b를 받은 경우
    vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(3, vector<long long>(3)));

    dp[0][0][0] = 1;

    for(int i = 1; i <= n; i++){
        for(int t = 0; t < 3; t++){
            for(int b = 0; b < 3; b++){
                // g 선택
                dp[i][t][0] =(dp[i][t][0] + dp[i - 1][t][b]) % MOD;

                // t 선택
                if(t >= 1) dp[i][t][0] = (dp[i][t][0] +dp[i - 1][t - 1][b]) % MOD;

                // b 선
                if(b >= 1) dp[i][t][b] = (dp[i][t][b] + dp[i - 1][t][b - 1]) % MOD;               
            }
        }
    }

    long long ans = 0;
    for(int t = 0; t < 3; t++){
        for(int b = 0; b < 3; b++){
            ans = (ans + dp[n][t][b]) % MOD;
        }
    }

    cout << ans;

    return 0;
}
