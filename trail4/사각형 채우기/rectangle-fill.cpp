#include <iostream>
#include <vector>

using namespace std;

int n;

int main() {
    cin >> n;

    // Please write your code here.

    vector<int> dp(n + 1);
    dp[1] = 1;
    dp[2] = 2;

    for(int i = 3; i <= n; i++){
        dp[i] = (dp[i - 2] + dp[i - 1]) % 10007;
    }

    cout << dp[n];

    return 0;
}
