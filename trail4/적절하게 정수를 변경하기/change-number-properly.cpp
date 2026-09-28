#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int a[501];

int main() {
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }

    // Please write your code here.

    // dp[i][j][k]
    // i번째 배열에서
    // j를 선택
    // k는 다른 횟수

    // dp[i][j][k] = dp[i - 1][j][k], dp[i - 1][j - 1][k]

    vector<vector<vector<int>>> dp(
        N + 1,
        vector<vector<int>>(
            5,
            vector<int>(M + 1, -1)
        )
    );

    for(int j = 1; j <= 4; j++){
        if(a[1] == j)
            dp[1][j][0] = 1;
        else
            dp[1][j][0] = 0;
    }

    for(int i = 2; i <= N; i++){
        for(int j = 1; j <= 4; j++){
            for(int k = 0; k <= M; k++){
                int value = 0;
                
                if(a[i] == j) value = 1;

                // j랑 같은거 선택
                if(dp[i - 1][j][k] != -1) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k] + value);

                // j랑 다른거 선택
                if(k >= 1){
                    for(int p = 1; p <= 4; p++){
                        if(p == j) continue;

                        if(dp[i - 1][p][k - 1] != -1) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][p][k - 1] + value);
                    }
                }
            }
        }
    }

    int ans = 0;

    for(int i = 1; i <= 4; i++){
        for(int j = 0; j <= M; j++){
            ans = max(ans, dp[N][i][j]);
        }
    }

    cout << ans;



    return 0;
}
