#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int arr[100];

int main() {
    cin >> n;

    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    // Please write your code here.
    // dp[d] : d는 두 그룹의 차이
    // 즉, dp[0]이 값이 있어야 Yes

    vector<int> dp(2 * sum + 1, -1);
    dp[sum] = 0;

    for(int i = 0; i < n; i++){
        vector<int> next = dp;
        
        for(int d = -sum; d <= sum; d++){
            int idx = d + sum;

            if(dp[idx] == -1) continue;

            if(d + arr[i] <= sum){
                int nextIdx = d + arr[i] + sum;

                next[nextIdx] = max(next[nextIdx], dp[idx] + arr[i]);
                // dp[nextIdx] = max(dp[nextIdx], dp[idx] + arr[i]);
            }

            if(d - arr[i] >= -sum){
                int nextIdx = d - arr[i] + sum;

                next[nextIdx] = max(next[nextIdx], dp[idx]);
                // dp[nextIdx] = max(dp[nextIdx], dp[idx]);
            }
        }

        dp = next;
    }

    // if(dp[0] == -1) cout << "No";
    // else cout << "Yes";
    cout << dp[sum];

    return 0;
}
