#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<string> sequences;
vector<int> sub_mask;

void dfs(int depth, int sub, int mask){
    if(depth == N){
        sub_mask.push_back(mask);
        return;
    }
    
    dfs(depth + 1, sub, mask);

    int bit = sub & (1 << depth);
    if(bit != 0) dfs(depth + 1, sub, (mask | bit));
}

int main() {
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

                if(c == '.') c = sequences[i][j];
                else if(sequences[i][j] != c){
                    valid[mask] = false;
                    break;
                }
            }

            if(!valid[mask]) break;
        }
    }

    vector<int> dp(1 << N, N + 1);

    for(int mask = 1; mask < (1 << N); mask++){
        if(valid[mask]){
            dp[mask] = 1;
            continue;
        }

        sub_mask.clear();
        dfs(0, mask, 0);
        for(int i = 0; i < sub_mask.size(); i++){
            if(valid[sub_mask[i]]){
                dp[mask] = min(dp[mask], dp[sub_mask[i] ^ mask] + 1);
            }
        }
    }
    
    cout << dp[(1 << N) - 1];

    return 0;
}
