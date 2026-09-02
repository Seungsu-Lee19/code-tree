#include <iostream>

using namespace std;

int n, m;

int main() {
    cin >> n >> m;

    // Please write your code here.
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    int grid[n][m] = {};
    int dir = 0;
    int x = 0;
    int y = 0;

    for(int i = 1; i <= n*m; i++){
        grid[x][y] = i;

        // cout << grid[x][y] << " " << x << " " << y << endl;

        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if(nx < 0 || ny < 0 || nx >= n || ny >= m) dir = (dir + 1) % 4;
        else if(grid[nx][ny] != 0) dir = (dir + 1) % 4;

        x = x + dx[dir];
        y = y + dy[dir];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << char('A' + (grid[i][j] - 1) % 26) << " ";
            // cout << grid[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
