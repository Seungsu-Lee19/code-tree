#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int a[1005][105];

int main() {
    cin >> n >> m;


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    // Please write your code here.

    // dp[i][j]
    // i번째 방을
    // j에 들어감

    vector<vector<int>> dp(
        n + 1,
        vector<int>(m + 1, -1)
    );

    for(int j = 1; j <= m; j++){
        dp[1][j] = a[1][j];
    }

    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= m; j++){
            for(int k = 1; k <= m; k++){
                if(j == k) continue;

                if(dp[i - 1][k] == -1) continue;

                dp[i][j] = max(dp[i][j], dp[i - 1][k] + a[i][j]);
            }
        }
    }

    cout << *max_element(dp[n].begin(), dp[n].end());

    return 0;
}
