#include <iostream>

using namespace std;

int n;
int grid[20][20];

int dx[4] = {-1, -1, 1, 1};
int dy[4] = {1, -1, -1, 1};

int mining(int x, int y, int a, int b){
    int score = grid[x][y];
    int nx = x;
    int ny = y;

    for(int i = 0; i < a; i++){
        nx = nx + dx[0];
        ny = ny + dy[0];

        if(nx < 0 || ny < 0 || nx >= n || ny >= n) return 0;

        score += grid[nx][ny];
    }
    for(int i = 0; i < b; i++){
        nx = nx + dx[1];
        ny = ny + dy[1];

        if(nx < 0 || ny < 0 || nx >= n || ny >= n) return 0;

        score += grid[nx][ny];
    }
    for(int i = 0; i < a; i++){
        nx = nx + dx[2];
        ny = ny + dy[2];

        if(nx < 0 || ny < 0 || nx >= n || ny >= n) return 0;

        score += grid[nx][ny];
    }
    for(int i = 0; i < b; i++){
        nx = nx + dx[3];
        ny = ny + dy[3];

        if(nx < 0 || ny < 0 || nx >= n || ny >= n) return 0;
        if(nx == x && ny == y) return score;

        score += grid[nx][ny];
    }

    return score;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    int ans = 0;
    for(int i = 2; i < n; i++){
        for(int j = 1; j < n - 1; j++){
            for(int a = 1; a <= n - 1; a++){
                for(int b = 1; b <= n - 1; b++){
                    ans = max(ans, mining(i, j, a, b));
                }
            }
        }
    }

    cout << ans;

    return 0;
}
