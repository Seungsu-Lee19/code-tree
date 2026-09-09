#include <iostream>

using namespace std;

int N, M, K;
int grid[100][100];

bool sameBombs(int x, int y){
    int num = grid[x][y];
    int cnt = 1;
    for(int i = x + 1; i < N; i++){
        if(num == grid[i][y]) cnt++;
        else break;
    }

    if(cnt >= M){
        for(int k = 0; k < cnt; k++){
            grid[x + k][y] = 0;
        }

        return true;
    }

    return false;
}

void rotate(){
    int temp[200][200] = {0, };

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            temp[i][j] = grid[N - j - 1][i];
        }
    }
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            grid[i][j] = temp[i][j];
        }
    }
}

void drop(){
    int temp[200][200] = {0, };

    for(int y = 0; y < N; y++){
        int realX = N - 1;
        for(int x = N - 1; x >= 0; x--){
            if(grid[x][y]){
                temp[realX][y] = grid[x][y];
                realX--;
            }
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            grid[i][j] = temp[i][j];
        }
    }
}

int main() {
    cin >> N >> M >> K;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    for(int t = 0; t < K; t++){
        bool isBomb = false;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(grid[i][j]){
                    if(sameBombs(i, j)) isBomb = true;
                }
            }
        }

        if(isBomb){
            drop();
            t--;
            continue;
        }


        drop();
        rotate();
        drop();
        // for(int i = 0; i < N; i++){
        //     for(int j = 0; j < N; j++){
        //         cout << grid[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        // break;
    }

    while(1){
        bool isBomb = false;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(grid[i][j]){
                    if(sameBombs(i, j)) isBomb = true;
                }
            }
        }

        if(isBomb == false) break;


        drop();
        // rotate();
        // drop();
        // for(int i = 0; i < N; i++){
        //     for(int j = 0; j < N; j++){
        //         cout << grid[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        // break;
    }

    int cnt = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(grid[i][j]) cnt++;
        }
    }

    cout << cnt;

    return 0;
}
