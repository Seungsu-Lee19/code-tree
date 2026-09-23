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
    // A그룹의 합은 x
    // B그룹의 합은 sum - x
    // A그룹과 B그룹의 차이는 abs(x - (sum - x)) == abs(2x - sum)
    // x가 sum의 절반에 가까워질수록 최솟값.

    int max_x = sum / 2 + 1;
    vector<int> dp(max_x);
    
    for(int i = 0; i < n; i++){
        for(int j = max_x; j >= arr[i]; j--){
            dp[j] = max(dp[j], dp[j - arr[i]] + arr[i]);
        }
    }

    // cout << sum << endl;
    // for(int i = 0; i < max_x; i++){
    //     cout << i << " -> " << dp[i] << endl;
    // }

    cout << abs(sum - 2 * dp[max_x - 1]);

    return 0;
}
