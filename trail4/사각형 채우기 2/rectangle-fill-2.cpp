#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int main() {
    cin >> n;

    // Please write your code here.
    vector<long long> dp(max(n + 1, 3));
    dp[1] = 1;
    dp[2] = 3;

    for(int i = 3; i <= n; i++){
        dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % 10007;
    }

    cout << dp[n];

    return 0;
}
