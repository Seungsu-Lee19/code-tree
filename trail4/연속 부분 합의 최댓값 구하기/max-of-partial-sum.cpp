#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n;
int arr[100000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Please write your code here.

    vector<int> dp(n, INT_MIN);
    dp[0] = arr[0];

    for(int i = 1; i < n; i++){
        dp[i] = max(dp[i - 1] + arr[i], arr[i]);
    }

    cout << *max_element(dp.begin(), dp.end());

    return 0;
}
