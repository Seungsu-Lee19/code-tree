#include <iostream>

using namespace std;

int n;
int r, c;
int a[101][101];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {
    cin >> n >> r >> c;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    // Please write your code here.
    cout << a[r][c] << " ";
    while(1){
        int max_dir = -1;
        for(int k = 0; k < 4; k++){
            int nx = r + dx[k];
            int ny = c + dy[k];

            if(nx < 1 || ny < 1 || nx > n || ny > n) continue;

            if(a[r][c] < a[nx][ny]) {
                max_dir = k;
                r = nx;
                c = ny;
                break;
            }
        }

        if(max_dir == -1) break;
        // cout << r << " " << c << endl;
        cout << a[r][c] << " ";
    }

    return 0;
}