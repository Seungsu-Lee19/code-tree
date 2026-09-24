#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int coin[1001];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> coin[i];
    }

    // Please write your code here.
    // dp[i][j] => i번째 계단까지 1칸씩 j번 올라왔을 때 최댓값
    // dp[i][j] == max(dp[i - 2][j], dp[i - 1][j - 1]) + coin

    vector<vector<int>> dp(n + 1, vector<int>(4, -1));
    dp[0][0] = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 4; j++){
            if(i - 2 >= 0 && dp[i - 2][j] != -1) dp[i][j] = max(dp[i][j], dp[i - 2][j] + coin[i]);

            if(j >= 1 && dp[i - 1][j - 1] != -1) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + coin[i]);
        }
    }

    cout << *max_element(dp[n].begin(), dp[n].end());

    return 0;
}
