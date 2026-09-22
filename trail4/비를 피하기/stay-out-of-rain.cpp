#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int n, h, m;
int grid[100][100];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int bfs(int sx, int sy){
    queue<pair<int, int>> q;
    vector<vector<int>> visited(n, vector<int>(n));

    q.push({sx, sy});
    visited[sx][sy] = 1;

    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();

        if(grid[x][y] == 3) return visited[x][y];

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

            if(visited[nx][ny] == 0 && grid[nx][ny] != 1){
                visited[nx][ny] = visited[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    return -1;
}

int main() {
    cin >> n >> h >> m;

    vector<pair<int, int>> people;
    vector<vector<int>> ans(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 2) people.push_back({i, j});
        }
    }

    // Please write your code here.

    for(auto [x, y] : people){
        int cnt = bfs(x, y);
        
        if(cnt != -1) cnt--;

        ans[x][y] = cnt;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
