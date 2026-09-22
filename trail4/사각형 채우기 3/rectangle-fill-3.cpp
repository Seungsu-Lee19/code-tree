#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int main() {
    cin >> n;

    // Please write your code here.
    const long long mod = 1000000007;
    vector<long long> dp(max(n + 1, 4));
    dp[1] = 2;
    dp[2] = 7;
    dp[3] = 22;

    for(int i = 4; i <= n; i++){
        dp[i] = (dp[i - 1] * 3 + dp[i - 2] - dp[i - 3] + mod) % mod;
    }

    cout << dp[n];

    return 0;
}
