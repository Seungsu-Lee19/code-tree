#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n, k;
string str;

int main() {
    cin >> n >> k;
    cin >> str;

    // Please write your code here.

    // dp[i][j][k]
    // i번째 수정 
    // j현재 위치
    // k번 이동

    // dp[i][j] = dp[i-1][j][0], dp[i-1][j - 1][1], dp[i-1][j - 1][k]

    vector<vector<vector<int>>> dp(
        n + 1,
        vector<vector<int>>(
            2,
            vector<int>(k + 1, INT_MIN)
        )
    );
    dp[0][0][0] = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 2; j++){
            for(int m = 0; m <= k; m++){
                int value = 0;

                if(str[i - 1] == 'L' && j == 0) value = 1;
                else if(str[i - 1] == 'R' && j == 1) value = 1; 

                // 현재 위치 j에서 그대로 있었음
                if(dp[i - 1][j][m] != -1){
                    dp[i][j][m] = max(
                        dp[i][j][m],
                        dp[i - 1][j][m] + value
                    );
                }

                // 반대편에서 현재 위치 j로 이동했음
                if(m >= 1 && dp[i - 1][1 - j][m - 1] != -1){
                    dp[i][j][m] = max(
                        dp[i][j][m],
                        dp[i - 1][1 - j][m - 1] + value
                    );
                }
                
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j <= k; j++){
            ans = max(ans, dp[n][i][j]);
        }
    }

    cout << ans;

    return 0;
}
