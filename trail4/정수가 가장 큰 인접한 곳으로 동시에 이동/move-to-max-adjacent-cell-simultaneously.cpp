#include <iostream>

using namespace std;

int n, m, t;
int a[21][21];
int grid[21][21] = {0, };
int temp[21][21] = {0, };
int r, c;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void move(int x, int y){
    int v = 0;
    int move_x, move_y;
    for(int k = 0; k < 4; k++){
        int nx = x + dx[k];
        int ny = y + dy[k];

        if(nx < 1 || ny < 1 || nx > n || ny > n) continue;

        if(v < a[nx][ny]){
            v = a[nx][ny];
            move_x = nx;
            move_y = ny;
        }
    }

    temp[move_x][move_y]++;
}

void check(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(temp[i][j] >= 2) temp[i][j] = 0;

            grid[i][j] = temp[i][j];
            temp[i][j] = 0;
        }
    }
}

int main() {
    cin >> n >> m >> t;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        cin >> r >> c;
        grid[r][c] = 1;
    }

    // Please write your code here.
    for(int time = 0; time < t; time++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(grid[i][j]) move(i, j);
            }
        }

        check();
    }

    int cnt = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(grid[i][j]) cnt++;
        }
    }
    cout << cnt;

    return 0;
}
