#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int n;
int r1, c1, r2, c2;

int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

int bfs(int sx, int sy, int fx, int fy){
    queue<pair<int, int>> q;
    vector<vector<int>> visited(n, vector<int>(n));

    q.push({sx, sy});
    visited[sx][sy] = 1;

    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();

        if(x == fx && y == fy) return visited[x][y];

        for(int i = 0; i < 8; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

            if(visited[nx][ny] == 0){
                visited[nx][ny] = visited[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    return -1;
}

int main() {
    cin >> n;
    cin >> r1 >> c1 >> r2 >> c2;

    // Please write your code here.
    int ans = bfs(r1 - 1, c1 - 1, r2 - 1, c2 - 1);

    if(ans == -1) cout << ans;
    else cout << ans - 1;

    return 0;
}
