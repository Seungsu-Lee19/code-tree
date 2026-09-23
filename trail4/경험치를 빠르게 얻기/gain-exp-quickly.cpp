#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n, m;
int e[100], t[100];

int main() {
    cin >> n >> m;
    vector<int> dp(2 * m + 1, 1000000000);
    for (int i = 0; i < n; i++) {
        cin >> e[i] >> t[i];
        // if(e[i] <= m) dp[e[i]] = t[i];
    }

    // Please write your code here.
    dp[0] = 0;

    for(int i = 0; i < n; i++){
        for(int j = 2 * m; j >= e[i]; j--){
            // if(dp[j - e[i]] != -1) dp[j] = min(dp[j], dp[j - e[i]] + t[i]);
            dp[j] = min(dp[j], dp[j - e[i]] + t[i]);
        }
    }

    // for(int i = 0; i <= 2 * m; i++){
    //     cout << i << " -> " << dp[i] << endl;
    // }

    int ans = *min_element(dp.begin() + m, dp.end());
    if(ans == 1000000000) ans = -1;
    
    cout << ans;

    return 0;
}
