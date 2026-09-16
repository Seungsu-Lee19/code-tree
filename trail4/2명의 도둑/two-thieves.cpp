#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int n, m, c;
int ans = 0;
vector<vector<int>> weight;
vector<pair<int, int>> candi;

void check(){
    int s = 0;
    for(auto [x, y]: candi){
        vector<int> dp(c + 1, 0);
        for(int j = y; j < y + m; j++){
            int w = weight[x][j];

            for(int cost = c; cost >= w; cost--){
                dp[cost] = max(dp[cost], dp[cost - w] + w * w);
            }
        }
        s += dp[c];
    }
    // dp로 푼다면
    // dp[0] = 0, dp[1] = dp[0] + 가능한 최대 값
    // dp[n + 1] = dp[n] + 가능한 최대 값.
    ans = max(ans, s);
}

void back(int cnt){
    if(cnt == 2){
        check();
        return;
    }

    auto [x, y] = candi[0];
    for(int i = x; i < n; i++){
        for(int j = 0; j <= n - m; j++){
            if(i == x){
                if(y + m <= j){ // 가능
                    candi.push_back({i, j});
                    back(cnt + 1);
                    candi.pop_back();
                }
            }
            else{
                candi.push_back({i, j});
                back(cnt + 1);
                candi.pop_back();
            }
        }
    }
}

int main() {
    cin >> n >> m >> c;

    weight.resize(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> weight[i][j];
        }
    }

    // Please write your code here.

    // 1행, 1열부터 가능한 영역을 찾아야 함.
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= n - m; j++){ 
            candi.push_back({i, j});
            back(1);
            candi.pop_back();
        }
    }

    cout << ans;

    return 0;
}