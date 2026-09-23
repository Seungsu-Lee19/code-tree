#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int A[100];

int main() {
    cin >> n >> m;

    vector<int> dp(m + 1, 10001);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        // if(A[i] <= m) dp[A[i]] = 1;
    }
    dp[0] = 0;

    // Please write your code here.
    for(int j = 0; j < n; j++){
        for(int i = m; i >= A[j]; i--){
            if(i >= A[j]) dp[i] = min(dp[i], dp[i - A[j]] + 1);
        }
    }

    if(dp[m] == 10001) dp[m] = -1;
    
    cout << dp[m];

    return 0;
}
