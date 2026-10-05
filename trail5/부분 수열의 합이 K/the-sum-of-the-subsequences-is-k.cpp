#include <iostream>
#include <vector>

using namespace std;

int n, k;
int arr[1001];

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    vector<int> prefix_sum(n + 1);
    prefix_sum[0] = 0;

    for(int i = 1; i <= n; i++){
        prefix_sum[i] = prefix_sum[i - 1] + arr[i];
    }

    int ans = 0;
    for(int i = 0; i <= n; i++){
        for(int j = i; j <= n; j++){
            if(prefix_sum[j] - prefix_sum[i] == k) {
                ans++;
                // cout << i << " " << j << endl;
            }
        }
    }

    cout << ans;
    

    return 0;
}
