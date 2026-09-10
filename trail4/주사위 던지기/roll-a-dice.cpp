#include <iostream>

using namespace std;

int n, m;
int r, c;
char directions;

int top = 1;
int bottom = 6;
int front = 2;
int back = 5;
int ri = 3;
int le = 4;

void roll_L(){
    int temp = top;
    top = ri;
    ri = bottom;
    bottom = le;
    le = temp;
}

void roll_R(){
    int temp = top;
    top = le;
    le = bottom;
    bottom = ri;
    ri = temp;
}

void roll_U(){
    int temp = top;
    top = front;
    front = bottom;
    bottom = back;
    back = temp;
}

void roll_D(){
    int temp = top;
    top = back;
    back = bottom;
    bottom = front;
    front = temp;
}

int main() {
    cin >> n >> m >> r >> c;

    int nx, ny;
    int grid[101][101] = {0, };
    grid[r][c] = 6;

    for (int i = 0; i < m; i++) {
        cin >> directions;

        if(directions == 'L'){
            nx = r;
            ny = c - 1;

            if(nx < 1 || ny < 1 || nx > n || ny > n) continue;

            roll_L();
        }
        else if(directions == 'R'){
            nx = r;
            ny = c + 1;

            if(nx < 1 || ny < 1 || nx > n || ny > n) continue;

            roll_R();
        }
        else if(directions == 'U'){
            nx = r - 1;
            ny = c;

            if(nx < 1 || ny < 1 || nx > n || ny > n) continue;

            roll_U();
        }
        else{
            nx = r + 1;
            ny = c;

            if(nx < 1 || ny < 1 || nx > n || ny > n) continue;

            roll_D();
        }
        
        r = nx;
        c = ny;
        grid[r][c] = bottom;
    }

    // Please write your code here.
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cnt += grid[i][j];
        }
    }

    cout << cnt;

    return 0;
}
