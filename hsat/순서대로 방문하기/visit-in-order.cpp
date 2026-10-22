#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> grid;
vector<pair<int, int>> points;
vector<vector<bool>> visited;

int dx[4] = {-1, 1, 0 ,0};
int dy[4] = {0, 0, -1, 1};

int ans = 0;

void dfs(int x, int y, int idx){
    if(x == points[idx].first && y == points[idx].second){
        idx++;

        if(idx == m) {
            ans++;
            return;
        }
    }

    // cout << x << " " << y << endl;

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

        if(grid[nx][ny] == 0 && !visited[nx][ny]){
            visited[nx][ny] = true;
            dfs(nx, ny, idx);
            visited[nx][ny] = false;
        }
    }
}

int main() {
    cin >> n >> m;

    grid.resize(n, vector<int>(n));
    visited.resize(n, vector<bool>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    points.resize(m);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        points[i] = {x - 1, y - 1};
    }

    // Please write your code here.
    auto [sx, sy] = points[0];
    visited[sx][sy] = true;
    dfs(sx, sy, 1);

    cout << ans;

    return 0;
}
