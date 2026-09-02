#include <iostream>

using namespace std;

int N, M;
int r, c;

int main() {
    cin >> N >> M;

    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};

    int grid[N][N] = {};

    for (int i = 0; i < M; i++) {
        cin >> r >> c;
        r--;
        c--;
        grid[r][c] = 1;

        int cnt = 0;
        for(int k = 0; k < 4; k++){
            int nx = r + dx[k];
            int ny = c + dy[k];

            if(nx < 0 || ny < 0 || nx >= N  || ny >= N) continue;

            if(grid[nx][ny] == 1) cnt++;
        }

        if(cnt == 3) cout << 1 << endl;
        else cout << 0 << endl;
    }

    // Please write your code here.

    return 0;
}