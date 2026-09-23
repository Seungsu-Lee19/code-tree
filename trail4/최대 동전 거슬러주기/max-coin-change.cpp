#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int coin[100];

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> coin[i];
    }

    // Please write your code here.
    vector<int> dp(M + 1, -1);
    dp[0] = 0;

    for(int i = 1; i <= M; i++){
        for(int j = 0; j < N; j++){
            if(i - coin[j] >= 0 && dp[i - coin[j]] != -1) dp[i] = max(dp[i], dp[i - coin[j]] + 1);
        }
        // cout << i << " -> " << dp[i] << endl;
    }

    if(dp[M] == 0) dp[M] = -1;
    
    cout << dp[M];

    return 0;
}
