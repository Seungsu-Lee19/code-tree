#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int A[100];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    // Please write your code here.
    vector<int> dp(m + 1, 100001);
    dp[0] = 0;

    for(int i = 0; i < n; i++){
        for(int j = m; j >= A[i]; j--){
            dp[j] = min(dp[j], dp[j - A[i]] + 1);
        }
    }

    if(dp[m] == 100001) cout << "No";
    else cout << "Yes";

    return 0;
}
