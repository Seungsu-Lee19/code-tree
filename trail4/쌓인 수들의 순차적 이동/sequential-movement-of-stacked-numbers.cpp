#include <iostream>

using namespace std;

int n, m;
int grid[20][20][400];
int move_nums[100];

int idx[20][20];

int dx[8] = {0, 0, 1, -1, -1, -1, 1, 1};
int dy[8] = {1, -1, 0, 0, -1, 1, 1, -1};

void moving(int x, int y, int k){
    int v = 0;
    int move_x, move_y;
    for(int d = 0; d < 8; d++){
        int nx = x + dx[d];
        int ny = y + dy[d];

        if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

        for(int id = 0; id < idx[nx][ny]; id++){
            if(v < grid[nx][ny][id]){
                v = grid[nx][ny][id];
                move_x = nx;
                move_y = ny;
            }
        }
    }

    if(v == 0) return;

    // cout << x << " -> " << move_x << endl;
    // cout << y << " -> " << move_y << endl;
    for(int id = k; id < idx[x][y]; id++){
        // cout << grid[x][y][id] << " ";
        grid[move_x][move_y][idx[move_x][move_y]] = grid[x][y][id];
        grid[x][y][id] = 0;
        idx[move_x][move_y]++;
    }
    idx[x][y] -= (idx[x][y] - k);
    // cout << "\n" << idx[x][y] << "\n" << endl;

    return;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j][0];
            idx[i][j] = 1;
        }
    }

    for (int i = 0; i < m; i++) {
        cin >> move_nums[i];
    }

    // Please write your code here.
    for(int num = 0; num < m; num++){
        bool isFind = false;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                for(int k = 0; k < idx[i][j]; k++){
                    if(move_nums[num] == grid[i][j][k]){
                        // cout << "move : " << i << " , " << j << " => " << grid[i][j][k] << endl; 
                        moving(i, j, k);
                        isFind = true;
                        break;
                    }
                }
                if(isFind) break;
            }
            if(isFind) break;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(idx[i][j] == 0){
                cout << "None\n";
                continue;
            }

            for(int k = idx[i][j] - 1; k >= 0; k--){
                cout << grid[i][j][k] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
