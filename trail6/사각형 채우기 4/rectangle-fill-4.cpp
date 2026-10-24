#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    if (n % 2 == 1) {
        cout << 0;
        return 0;
    }

    const int MOD = 10007;
    vector<int> dp(n + 1, 0);

    dp[0] = 1;
    dp[2] = 3;

    for (int i = 4; i <= n; i += 2) {
        dp[i] = (4 * dp[i - 2] - dp[i - 4] + MOD) % MOD;
    }

    cout << dp[n];
    return 0;
}