#include <iostream>
#include <utility>

using namespace std;

int n, m;
int grid[20][20];

int dx[8] = {0, 0, 1, -1, -1, -1, 1, 1};
int dy[8] = {-1, 1, 0, 0, -1, 1, 1, -1};

pair<int, int> find_v(int v){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == v) return {i, j};
        }
    }
}

void change(int x, int y){
    int max_v = 0;
    int max_x, max_y;
    for(int i = 0; i < 8; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

        if(grid[nx][ny] > max_v){
            max_v = grid[nx][ny];
            max_x = nx;
            max_y = ny;
        }
    }

    int temp = grid[x][y];
    grid[x][y] = grid[max_x][max_y];
    grid[max_x][max_y] = temp;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    for(int i = 1; i <= m; i++){
        for(int v = 1; v <= n*n; v++){
            auto [x, y] = find_v(v);
            change(x, y);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
