#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> grid;
vector<vector<int>> visited;

int dx[2] = {1, 0};
int dy[2] = {0, 1};

void bfs(int x, int y){
    visited[x][y] = 1;

    for(int i = 0; i < 2; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

        if(grid[nx][ny] == 1 && visited[nx][ny] == 0) bfs(nx, ny); 
    }
}

int main() {
    cin >> n >> m;

    grid.resize(n, vector<int>(m));
    visited.resize(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    bfs(0, 0);
    if(visited[n - 1][m - 1] == 1) cout << 1;
    else cout << 0;

    return 0;
}
