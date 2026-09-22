#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int main() {
    cin >> n;

    // Please write your code here.
    vector<int> dp(max(n + 1, 4));
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    // dp[3] = 5;

    for(int i = 3; i <= n; i++){
        int s = 0;
        for(int p = 1; p <= i; p++){
            s = s + dp[p - 1] * dp[i - p];
        }
        dp[i] = s;
    }

    cout << dp[n];


    return 0;
}
