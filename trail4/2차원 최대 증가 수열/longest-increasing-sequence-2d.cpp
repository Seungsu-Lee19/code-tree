#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int grid[50][50];
vector<vector<int>> dp;

void check(int x, int y){
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            if(x - i < 1 || y - j < 1) continue;
            if(dp[i][j] == 0) continue;

            if(grid[x][y] > grid[i][j]){
                dp[x][y] = max(dp[x][y], dp[i][j] + 1);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    dp.resize(n, vector<int>(m, 0));
    dp[0][0] = 1;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            check(i, j);
        }
    }

    int ans = 0;
    for(auto& row : dp){
        ans = max(ans, *max_element(row.begin(), row.end()));
    }
    cout << ans;

    // cout << endl;
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    return 0;
}
