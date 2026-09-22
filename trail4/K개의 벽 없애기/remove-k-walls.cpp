#include <iostream>
#include <tuple>
#include <queue>
#include <vector>

using namespace std;

int n, k;
int grid[100][100];
int r1, c1, r2, c2;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int bfs(int sx, int sy, int fx, int fy){
    queue<tuple<int, int, int>> q;
    vector<vector<vector<int>>> visited(n, vector<vector<int>>(n, vector<int>(k + 1)));
    
    q.push({sx, sy, 0});
    visited[sx][sy][0] = 1;

    while(!q.empty()){
        auto [x, y, wall] = q.front();
        q.pop();

        if(x == fx && y == fy) return visited[x][y][wall];

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

            if(grid[nx][ny] == 0 && visited[nx][ny][wall] == 0){
                visited[nx][ny][wall] = visited[x][y][wall] + 1;
                q.push({nx, ny, wall});
            }
            else if(grid[nx][ny] == 1 && wall < k && visited[nx][ny][wall + 1] == 0){
                visited[nx][ny][wall + 1] = visited[x][y][wall] + 1;
                q.push({nx, ny, wall + 1});
            }
        }
    }

    return -1;
}

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cin >> r1 >> c1;
    cin >> r2 >> c2;

    r1--;
    c1--;
    r2--;
    c2--;

    // Please write your code here.

    int ans = bfs(r1, c1, r2, c2);
    if(ans == -1) cout << ans;
    else cout << ans - 1;

    return 0;
}
