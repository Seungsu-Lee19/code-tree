#include <iostream>

using namespace std;

int n;
int grid[200][200];
int r, c;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cin >> r >> c;

    // Please write your code here.
    r--;
    c--;

    int cnt = grid[r][c];
    grid[r][c] = 0;
    for(int k = 0; k < 4; k++){
        for(int q = 1; q <= cnt - 1; q++){
            int nx = r + (dx[k] * q);
            int ny = c + (dy[k] * q);

            if(nx < 0 || ny < 0 || nx >= n || ny >= n) break;

            grid[nx][ny] = 0;
        }
    }

    int temp[200][200] = {0, };
    for(int y = 0; y < n; y++){
        int i = n - 1;
        for(int x = n - 1; x >= 0; x--){
            if(grid[x][y] > 0) {
                temp[i][y] = grid[x][y];
                i--; 
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << temp[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
