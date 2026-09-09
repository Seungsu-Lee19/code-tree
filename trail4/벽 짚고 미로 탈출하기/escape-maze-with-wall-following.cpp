#include <iostream>

using namespace std;

int N;
int start_x, start_y;
char grid[105][105];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main() {
    cin >> N;
    cin >> start_x >> start_y;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> grid[i][j];
        }
    }

    int cnt = 0;
    for(int k = 0; k < 4; k++){
        int i = start_x + dx[k];
        int j = start_y + dy[k];

        if(i < 1 || j < 1 || i > N || j > N) continue;

        if(grid[i][j] == '#') cnt++;
    }

    if(cnt == 4){
        cout << -1;
        return 0;
    }

    // Please write your code here.
    int t = 0;
    int dir = 0;
    int x = start_x;
    int y = start_y;
    while(1){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        
        if(x == start_x && y == start_y && t != 0 && dir == 0){
            t = -1;
            break;
        }

        if(nx < 1 || ny < 1 || nx > N || ny > N){
            t++;
            break;
        }

        if(grid[nx][ny] == '#'){
            dir = ((dir - 1) + 4) % 4;
            continue;
        }
        

        
        // cout << nx << " " << ny << " " << dir << endl;
        t++;
        x = nx;
        y = ny;

        dir = (dir + 1) % 4;
        int nx2 = nx + dx[dir];
        int ny2 = ny + dy[dir];

        if(grid[nx2][ny2] == '#'){
            dir = ((dir - 1) + 4) % 4;
            continue;
        }

    }
    cout << t;
    return 0;
}