#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int grid[100][100];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.

    vector<vector<int>> dp(n, vector<int>(n, 200000001));
    dp[0][n - 1] = grid[0][n - 1];

    for(int i = 0; i < n; i++){
        for(int j = n - 1; j >= 0; j--){
            int nx1 = i;
            int ny1 = j - 1;

            if(nx1 >= 0 && ny1 >= 0 && nx1 < n && ny1 < n){
                dp[nx1][ny1] = min(dp[nx1][ny1], dp[i][j] + grid[nx1][ny1]);
            }

            
            int nx2 = i + 1;
            int ny2 = j;

            if(nx2 >= 0 && ny2 >= 0 && nx2 < n && ny2 < n){
                dp[nx2][ny2] = min(dp[nx2][ny2], dp[i][j] + grid[nx2][ny2]);
            }
        }
    }

    cout << dp[n - 1][0];

    return 0;
}
