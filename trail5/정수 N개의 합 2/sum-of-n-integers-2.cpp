#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n, k;
int arr[100000];

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Please write your code here.
    vector<int> ve;
    ve.push_back(arr[0]);

    for(int i = 1; i < n; i++){
        ve.push_back(ve.back() + arr[i]);
    }

    int ans = INT_MIN;
    for(int i = 0; i < n - k; i++){
        ans = max(ans, ve[i + k] - ve[i]);
    }

    cout << ans;

    return 0;
}
