#include <iostream>

using namespace std;

int n;
int grid[50][50];
int temp[50][50];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

void drop(){
    int grid2[50][50] = {0, };

    for(int y = 0; y < n; y++){
        int realX = n - 1;
        for(int x = n - 1; x >= 0; x--){
            if(temp[x][y]){
                grid2[realX][y] = temp[x][y];
                realX--;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            temp[i][j] = grid2[i][j];
        }
    }

    return;
}

void bomb(int x, int y){
    int power = grid[x][y];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            temp[i][j] = grid[i][j];
        }
    }
    temp[x][y] = 0;

    for(int k = 0; k < 4; k++){
        for(int p = 1; p < power; p++){
            int nx = x + (dx[k] * p);
            int ny = y + (dy[k] * p);

            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

            temp[nx][ny] = 0;
        }
    }

    drop();

    return;
}

int count(){
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(temp[i][j] == 0) continue;
            
            for(int k = 0; k < 2; k++){
                int nx = i + dx[k];
                int ny = j + dy[k];

                if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

                if(temp[nx][ny] == temp[i][j]) cnt++;
            }
        }
    }

    return cnt;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    int ans = -1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            bomb(i, j);
            ans = max(ans, count());
        }
    }
    
    cout << ans;

    return 0;
}
