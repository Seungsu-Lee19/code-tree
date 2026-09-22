#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int n, k;
int grid[100][100];
vector<vector<int>> visited;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int bfs(int sx, int sy){
    queue<pair<int, int>> q;

    q.push({sx, sy});
    visited[sx][sy] = 0;

    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();

        if(grid[x][y] == 2) return visited[x][y];

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

            if(visited[nx][ny] == -1 && grid[nx][ny] != 0){
                visited[nx][ny] = visited[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    return -1;
}

int main() {
    cin >> n >> k;

    vector<pair<int, int>> g;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 2) g.push_back({i, j});
        }
    }

    // Please write your code here.
    visited.resize(n, vector<int>(n));
    vector<vector<int>> ans(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(grid[i][j] == 1){
                visited.assign(n, vector<int>(n, -1));
                ans[i][j] = bfs(i, j);
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(grid[i][j] == 0) cout << "-1 ";
            else if(grid[i][j] == 2) cout << "0 ";
            else if(ans[i][j] == -1) cout << "-2 ";
            else cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
