#include <iostream>

using namespace std;

int n;
int grid[100][100];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    int ans = 0;
    for(int x = 0; x < n; x++){
        for(int y = 0; y < n; y++){
            int cnt = 0;
            for(int k = 0; k < 4; k++){
                int nx = x + dx[k];
                int ny = y + dy[k];

                if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

                if(grid[nx][ny] == 1) cnt++;
            }
            if(cnt >= 3) ans++;
        }
    }

    cout << ans;

    return 0;
}