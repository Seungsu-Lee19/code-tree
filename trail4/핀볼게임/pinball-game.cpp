#include <iostream>

using namespace std;

int n;
int grid[100][100];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int ball(int x, int y, int dir){
    int cnt = 1;

    while(1){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        // cout << nx << " " << ny << endl;

        if(nx < 0 || ny < 0 || nx >= n || ny >= n) break;

        if(grid[nx][ny] == 1){
            if(dir == 0) dir = 3;
            else if(dir == 1) dir = 2;
            else if(dir == 2) dir = 1;
            else dir = 0;
        }
        else if(grid[nx][ny] == 2){
            if(dir == 0) dir = 1;
            else if(dir == 1) dir = 0;
            else if(dir == 2) dir = 3;
            else dir = 2;
        }

        x = nx;
        y = ny;
        cnt++;
    }

    return cnt;
}
int main() {
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> grid[i][j];

    // Please write your code here.

    int ans = -1;
    for(int y = 0; y < n; y++){
        ans = max(ans, ball(-1, y, 2));
    }
    
    for(int x = 0; x < n; x++){
        ans = max(ans, ball(x, n, 1));
    }

    for(int y = 0; y < n; y++){
        ans = max(ans, ball(n, y, 0));
    }
    
    for(int x = 0; x < n; x++){
        ans = max(ans, ball(x, -1, 3));
    }

    // cout << ball(4, -1, 3) << endl;
    
    cout << ans;


    return 0;
}
