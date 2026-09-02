#include <iostream>
#include <string>

using namespace std;

int N, T;
string str;
int board[100][100];

int main() {
    cin >> N >> T;
    cin >> str;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    // Please write your code here.
    int dir = 0;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};

    int x = N / 2;
    int y = N / 2;
    int ans = board[x][y];

    for(int i = 0; i < str.length(); i++){
        char cmd = str[i];
        
        if(cmd == 'F'){
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;

            ans += board[nx][ny];
            x = nx;
            y = ny;
        }
        else if(cmd == 'L'){
            dir = (dir + 1) % 4;
        }
        else{
            dir = ((dir - 1) + 4) % 4;
        }
    }

    cout << ans;

    return 0;
}