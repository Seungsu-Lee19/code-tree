#include <iostream>

using namespace std;

int n, m;
int grid[20][20];

int get_rect(int x, int y, int a, int b){
    int cnt = 0;
    for(int i = x; i < a; i++){
        for(int j = y; j < b; j++){
            if(grid[i][j] <= 0) return -1;

            cnt++;
        }
    }
    
    if(cnt == 0) return -1;

    return cnt;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.

    int ans = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for(int a = i; a <= n; a++){
                for(int b = j; b <= m; b++){
                    ans = max(ans, get_rect(i, j, a, b));
                }
            }
        }
    }
    cout << ans;

    return 0;
}
