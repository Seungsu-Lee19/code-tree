#include <iostream>
#include <utility>
#include <queue>

using namespace std;

int n, k;
int grid[100][100];
int visited[100][100] = {0, };
int r, c;
int ans = 0;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void bfs(int sx, int sy){
    queue<pair<int, int>> q;
    q.push({sx, sy});
    visited[sx][sy] = 1;

    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();
        ans++;

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

            if(visited[nx][ny] == 0 && grid[nx][ny] == 0){
                q.push({nx, ny});
                visited[nx][ny] = 1;
            }
        }
    }
}

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> grid[i][j];

    for (int i = 0; i < k; i++) {
        cin >> r >> c;

        if(visited[r - 1][c - 1] == 0) bfs(r - 1, c - 1);
    }

    cout << ans;
    // Please write your code here.

    return 0;
}
