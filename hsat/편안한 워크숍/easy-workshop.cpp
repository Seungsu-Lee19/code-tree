#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int N, K;

vector<vector<int>> grid;

vector<vector<vector<int>>> dp;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int ans = INT_MAX;

int dfs(int x, int y, int depth){
    if(dp[x][y][depth] != -1) return dp[x][y][depth];

    if(depth == 1){
        dp[x][y][depth] = 0;
        return dp[x][y][depth];
    }


    int best = INT_MAX;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;

        if(grid[nx][ny] - grid[x][y] > 0){
            best = min(best, max(dfs(nx, ny, depth - 1), grid[nx][ny] - grid[x][y]));
        }
    }

    dp[x][y][depth] = best;
    return dp[x][y][depth];
}

int main() {
    cin >> N >> K;

    grid.resize(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    dp.resize(N, vector<vector<int>>(N, vector<int>(K + 1, -1)));
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            ans = min(ans, dfs(i, j, K));
        }
    }

    if(ans == INT_MAX) ans = -1;
    cout << ans;


    return 0;
}
