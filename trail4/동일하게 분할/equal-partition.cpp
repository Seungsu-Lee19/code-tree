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
    // dp[s] : s는 두 그룹의 합
    // 즉, dp[s / 2]이 값이 있어야 Yes

    if(sum % 2 != 0){
        cout << "No";
        return 0;
    }

    vector<bool> dp(sum / 2, false);
    dp[0] = true;

    for(int i = 0; i < n; i++){
        for(int j = sum / 2; j >= arr[i]; j--){
            if(dp[j-arr[i]]) dp[j] = true;
        }
    }

    if(dp[sum / 2]) cout << "Yes";
    else cout << "No";
    // cout << dp[sum / 2];

    return 0;
}
