#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n;
int cards[2001];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> cards[i];
    }

    // Please write your code here.

    // 1 ~ n까지 카드를 왼쪽 또는 오른쪽이 가져가
    // 1번 카드를 왼쪽이 가져가냐, 오른족이 가져가냐
    // 

    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, INT_MAX));
    dp[0][0] = 0;

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            int next = max(i, j) + 1;

            if(next > n) continue;

            long long cost1 = (i == 0) ? 0: abs(cards[i] - cards[next]);
            long long cost2 = (j == 0) ? 0: abs(cards[j] - cards[next]);

            dp[next][j] = min(dp[next][j], dp[i][j] + cost1);
            dp[i][next] = min(dp[i][next], dp[i][j] + cost2);
        }
    }

    // for(int i = 0; i <= n; i++){
    //     for(int j = 0; j <= n; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    long long ans = INT_MAX;
    for(int i = 0; i <= n; i++){
        ans = min(ans, dp[i][n]);
    }

    cout << ans;

    return 0;
}