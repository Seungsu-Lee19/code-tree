#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int grid[100][100];

int dx[2] = {0, 1};
int dy[2] = {1, 0};

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    vector<vector<int>> dp(n, vector<int>(n));
    dp[0][0] = grid[0][0];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int nx = i + dx[0];
            int ny = j + dy[0];

            if(nx >= 0 && ny >= 0 && nx < n && ny < n){
                dp[nx][ny] = max(dp[nx][ny], dp[i][j] + grid[nx][ny]);
            }
            
            int nx2 = i + dx[1];
            int ny2 = j + dy[1];

            if(nx2 >= 0 && ny2 >= 0 && nx2 < n && ny2 < n){
                dp[nx2][ny2] = max(dp[nx2][ny2], dp[i][j] + grid[nx2][ny2]);
            }
        }
    }

    cout << dp[n - 1][n - 1];

    return 0;
}
