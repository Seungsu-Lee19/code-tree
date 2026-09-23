#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int main() {
    cin >> n;

    // Please write your code here.
    vector<int> dp(n + 1);
    dp[0] = 1;
    int nums[] = {1, 2, 5};
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 3; j++){
            if(i - nums[j] >= 0) dp[i] = (dp[i] + dp[i - nums[j]]) % 10007;
        }
    }

    cout << dp[n];

    return 0;
}
