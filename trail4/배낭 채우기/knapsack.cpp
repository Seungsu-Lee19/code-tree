#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int w[100], v[100];

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> w[i] >> v[i];
    }

    // Please write your code here.
    vector<int> dp(M + 1);

    for(int i = 0; i < N; i++){
        for(int j = M; j >= w[i]; j--){
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }

    cout << *max_element(dp.begin(), dp.end());

    return 0;
}
