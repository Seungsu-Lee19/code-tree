#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n, k;
int numbers[100001];

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> numbers[i];
    }

    // Please write your code here.
    // dp[i][j] => i번째까지 선택하고, 음수가 j만큼 선택됨
    // 양수면, dp[i][j] = max(dp[i - 1][j] + numbers[i], numbers[i]);

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, INT_MIN));
    dp[0][0] = 0;

    int ans = INT_MIN;
    for(int i = 1; i <= n; i++){
        if(numbers[i] >= 0){
            dp[i][0] = numbers[i];
            for(int j = 0; j <= k; j++){
                if(dp[i - 1][j] == INT_MIN) continue;

                dp[i][j] = max(dp[i][j], dp[i - 1][j] + numbers[i]);
            }
        }
        else{
            dp[i][1] = numbers[i];

            for(int j = 1; j <= k; j++){
                if(dp[i - 1][j - 1] == INT_MIN) continue;
                
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + numbers[i]);
            }
        }

        for(int j = 0; j <= k; j++){
            ans = max(ans, dp[i][j]);
        }
    }

    // for(int i = 0; i < k; i++){
    //     cout << dp[n][i] << " ";
    // }
    // cout << endl;

    cout << ans;

    return 0;
}
