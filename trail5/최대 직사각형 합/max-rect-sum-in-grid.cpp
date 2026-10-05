#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int n;
int arr[301][301];

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }

    vector<vector<int>> sum(
        n + 1,
        vector<int>(n + 1)
    );

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + arr[i][j]; 
        }
    }

    int ans = INT_MIN;
    for(int x1 = 1; x1 <= n; x1++){
        for(int x2 = x1; x2 <= n; x2++){
            vector<int> dp(n + 1, INT_MIN);
            dp[0] = 0;
            for(int y = 1; y <= n; y++){
                int value = sum[x2][y] - sum[x1 - 1][y] - sum[x2][y - 1] + sum[x1 - 1][y - 1];
                dp[y] = max(value, dp[y - 1] + value); 
            }

            ans = max(ans, *max_element(dp.begin() + 1, dp.end()));
        }
    }
    cout << ans;

    return 0;
}