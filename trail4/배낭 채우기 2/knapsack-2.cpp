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

    for(int i = 1; i <= M; i++){
        for(int j = 0; j < N; j++){
            if(i - w[j] >= 0) dp[i] = max(dp[i], dp[i - w[j]] + v[j]);
        }
    }

    cout << dp[M];

    return 0;
}
