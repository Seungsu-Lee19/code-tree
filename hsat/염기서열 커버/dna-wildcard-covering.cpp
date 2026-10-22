#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, M;
vector<string> sequences;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    sequences.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> sequences[i];
    }

    vector<bool> valid(1 << N, true);

    for(int mask = 1; mask < (1 << N); mask++){
        for(int j = 0; j < M; j++){
            char c = '.';

            for(int i = 0; i < N; i++){
                if(!(mask & (1 << i))) continue;
                if(sequences[i][j] == '.') continue;

                if(c == '.'){
                    c = sequences[i][j];
                }
                else if(c != sequences[i][j]){
                    valid[mask] = false;
                    break;
                }
            }
            if(!valid[mask]) break;
        }
    }

    // dp[mask]
    vector<int> dp(1 << N, N + 1);

    for(int mask = 1; mask < (1 << N); mask++){
        if(valid[mask]){
            dp[mask] = 1;
            continue;
        }

        for (int sub = (mask - 1) & mask; sub > 0; sub = (sub - 1) & mask) {
            if (valid[sub]) {
                dp[mask] = min(dp[mask],
                               dp[mask ^ sub] + 1);
            }
        }
    }

    cout << dp[(1 << N) - 1];

    return 0;
}
