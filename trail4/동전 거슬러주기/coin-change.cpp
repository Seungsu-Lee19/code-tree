#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int N, M;
int coin[100];

int main() {
    cin >> N >> M;

    vector<int> dp(M + 1, INT_MAX - 1);
    dp[0] = 0;
    for (int i = 0; i < N; i++) {
        cin >> coin[i];
        if(coin[i] <= M) dp[coin[i]] = 1;
    }

    // Please write your code here.

    for(int i = 1; i <= M; i++){
        for(int j = 0; j < N; j++){
            if(i - coin[j] >= 0) dp[i] = min(dp[i], dp[i - coin[j]] + 1);
        }
        // cout << dp[i] << endl;
    }

    if(dp[M] == INT_MAX - 1) cout << -1;
    else cout << dp[M];

    return 0;
}
