#include <iostream>

using namespace std;

int n, m;
int grid[200][200];
int bomb_cols;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        cin >> bomb_cols;
        bomb_cols--;

        int r = -1;
        for(int i = 0; i < n; i++){
            if(grid[i][bomb_cols]){
                r = i;
                break;
            } 
        }

        if(r == -1) continue;

        int power = grid[r][bomb_cols];
        grid[r][bomb_cols] = 0;

        for(int k = 0; k < 4; k++){
            for(int p = 1; p < power; p++){
                int nx = r + (dx[k] * p);
                int ny = bomb_cols + (dy[k] * p);

                if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

                grid[nx][ny] = 0;
            }
        }

        int temp[200][200] = {0, };
        for(int y = 0; y < n; y++){
            int idx = n - 1;
            for(int x = n - 1; x >= 0; x--){
                if(grid[x][y]){
                    temp[idx][y] = grid[x][y];
                    idx--;
                }
            }
        }

        for(int p = 0; p < n; p++){
            for(int q = 0; q < n; q++){
                grid[p][q] = temp[p][q];
            }
        }
    }

    // Please write your code here.
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}