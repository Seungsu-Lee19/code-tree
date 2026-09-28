#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int N, M;
int s[201], e[201], v[201];

int main() {
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> s[i] >> e[i] >> v[i];
    }

    // Please write your code here.
    // dp[i][j]
    // i 일
    // j 옷

    // dp[i][j] = dp[i - 1][j] => 같은 옷을 입음
    // dp[i][j] = dp[i - 1][j - 1] + (A[i] - A[i - 1])
    vector<vector<int>> dp(
        M + 1,
        vector<int>(N + 1, INT_MIN)
    );

    for(int j = 1; j <= N; j++){
        if(s[j] <= 1 && 1 <= e[j]){
            dp[1][j] = 0;
        }
    }

    for(int i = 2; i <= M; i++){
        for(int j = 1; j <= N; j++){
            if(i < s[j] || i > e[j]) continue;

            for(int k = 1; k <= N; k++){
                if(i - 1 < s[k] || i - 1 > e[k]) continue;

                if(dp[i - 1][k] == INT_MIN) continue;

                dp[i][j] = max(dp[i][j], dp[i - 1][k] + abs(v[k] - v[j]));

            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= N; i++) ans = max(ans, dp[M][i]);
    cout << ans;

    return 0;
}
