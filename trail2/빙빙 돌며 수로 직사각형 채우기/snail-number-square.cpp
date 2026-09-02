#include <iostream>

using namespace std;

int n, m;
int arr[100][100];

int main() {
    cin >> n >> m;

    // Please write your code here.
    int grid[n][m] = {};
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    int x = 0;
    int y = 0;
    int dir = 0;

    int i = 1;
    while(1){
        if(i > n * m) break;

        grid[x][y] = i;
        i++;


        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if(nx < 0 || ny < 0 || nx >= n || ny >= m) dir = (dir + 1) % 4;
        else if(grid[nx][ny] != 0) dir = (dir + 1) % 4;

        x += dx[dir];
        y += dy[dir];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}