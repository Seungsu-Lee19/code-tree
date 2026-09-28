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
    // dp[i][j][k]
    // i 층까지
    // j 왼쪽, 오른쪽, 중앙
    // k == 0, 
    

    int ans = 0;
    for(int start = 0; start < 3; start ++){
        vector<vector<int>> dp(
            n + 1,
            vector<int>(3, -1)
        );

        if(start == 0) dp[1][0] = l[1];
        else if(start == 1) dp[1][1] = m[1];
        else dp[1][2] = r[1];

        for(int i = 2; i <= n; i++){
            for(int j = 0; j < 3; j++){
                if(i == n && j == start) continue;
                
                for(int k = 0; k < 3; k++){
                    if(j == k) continue;

                    if(dp[i - 1][k] == -1) continue;

                    if(j == 0) dp[i][j] = max(dp[i][j], dp[i - 1][k] + l[i]);
                    else if(j == 1) dp[i][j] = max(dp[i][j], dp[i - 1][k] + m[i]);
                    else dp[i][j] = max(dp[i][j], dp[i - 1][k] + r[i]);
                }
            }
        }

        if(start == 0) ans = max(ans, max(dp[n][1], dp[n][2]));
        else if(start == 1) ans = max(ans, max(dp[n][0], dp[n][2]));
        else ans = max(ans, max(dp[n][1], dp[n][0]));
        
    }

    cout << ans;

    return 0;
}
