#include <iostream>
#include <algorithm>

using namespace std;

int n;
int grid[100][100];
int visited[100][100] = {0, };
int cnt = 0;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void dfs(int x, int y, int value){
    visited[x][y] = 1;
    cnt++;

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

        if(grid[nx][ny] == value && visited[nx][ny] == 0) dfs(nx, ny, value);
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.

    int ans[2] = {0, };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cnt = 0;
            if(visited[i][j] == 0 && grid[i][j] > 0){
                dfs(i, j, grid[i][j]);

                if(cnt >= 4){
                    ans[0]++;
                }
                ans[1] = max(ans[1], cnt);
            }
        }
    }

    cout << ans[0] << " " << ans[1];

    return 0;
}
