#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n;
int arr[1000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Please write your code here.

    vector<int> dp(n, INT_MIN);

    dp[0] = 0;

    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(dp[j] == INT_MIN) continue;

            if(arr[j] >= i - j) dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    cout << *max_element(dp.begin(), dp.end());

    return 0;
}
