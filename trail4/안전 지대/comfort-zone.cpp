#include <iostream>
#include <vector>

using namespace std;

int N, M;
int grid[50][50];

vector<vector<int>> visited;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void dfs(int x, int y, int k){
    visited[x][y] = 1;

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

        if(grid[nx][ny] > k && visited[nx][ny] == 0) dfs(nx, ny, k);
    }
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    int ans[2] = {0, 1};
    visited.resize(N, vector<int>(M, 0));

    for(int k = 1; k <= 100; k++){
        visited.assign(N, vector<int>(M, 0));
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if(visited[i][j] == 0 && grid[i][j] > k){
                    dfs(i, j, k);
                    cnt++;
                }
            }
        }

        // cout << k << " -> " << cnt << endl;
        if(cnt > ans[0]) {
            ans[0] = cnt;
            ans[1] = k;
        }
    }

    cout << ans[1] << " " << ans[0];

    return 0;
}
