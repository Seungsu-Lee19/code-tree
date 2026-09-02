#include <iostream>

using namespace std;

int n;
char grid[1000][1000];
int k;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cin >> k;

    // Please write your code here.

    int ans = 0;
    int dir = (k - 1) / n;
    int x, y;
    // 0-0, 1-0, 2-0        0-0, 1-1, 2-2
    // 3-0, 4-1, 5-2        3-2, 4-2, 5-2
    // 6-2, 7-2, 8-2        6-2, 7-1, 8-0
    // 9-2, 10-1, 11-0      
    if(((k - 1) / n % 2) == 0){
        if(k <= n) {
            x = 0;
            y = (k - 1) % n;
        }
        else {
            x = n - 1;
            y = n - 1 - (k - 1) % n;
        }
    }
    else{
        if(k <= 2 * n){
            x = (k - 1) % n;
            y = n - 1;
        }
        else{
            x = n - 1 - (k - 1) % n;
            y = 0;
        }
    }

    // cout << x << " " << y << endl;

    // 위,오른쪽, 아래, 왼쪽
    while(1){
        int m = grid[x][y];
        int nx = x;
        int ny = y;

        if(m == '\\'){
            if(dir == 0){
                dir = 3;
                ny++;
            }
            else if(dir == 1){
                dir = 2;
                nx--;
            }
            else if(dir == 2){
                dir = 1;
                ny--;
            }
            else if(dir == 3){
                dir = 0;
                nx++;
            }
        }
        else{// 위,오른쪽, 아래, 왼쪽
            if(dir == 0){
                dir = 1;
                ny--;
            }
            else if(dir == 1){
                dir = 0;
                nx++;
            }
            else if(dir == 2){
                dir = 3;
                ny++;
            }
            else if(dir == 3){
                dir = 2;
                nx--;
            }
        }


        ans++;
        if(nx < 0 || ny < 0 || nx >= n || ny >= n) break;

        x = nx;
        y = ny;
    }

    cout << ans;

    return 0;
}