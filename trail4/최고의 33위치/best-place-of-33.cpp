#include <iostream>

using namespace std;

int N;
int grid[20][20];

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

    int nx, ny;
    int ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            int cnt = grid[i][j];
            for(int k = 0; k < 8; k++){
                nx = i + dx[k];
                ny = j + dy[k];

                if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;

                cnt += grid[nx][ny];
            }

            ans = max(ans, cnt);
        }
    }

    cout << ans;

    return 0;
}
