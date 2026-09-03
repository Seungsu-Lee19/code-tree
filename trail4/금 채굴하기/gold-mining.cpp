#include <iostream>

using namespace std;

int n, m;
int grid[20][20];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int cnt = 0;
int max_k = 0;

int mining(int x, int y, int k){
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(abs(x - i) + abs(y - j) <= k){
                cnt += grid[i][j];
            }
        }
    }

    return cnt;
}

int main() {
    cin >> n >> m;

    int gold = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];

            if(grid[i][j] == 1) gold++;
        }
    }

    // Please write your code here.

    int ans = 0;
    max_k = 2 * (n - 1);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k <= max_k; k++){
                int cnt = mining(i, j, k);
                
                if((k * k) + (k + 1) * (k + 1) <= cnt * m)  ans = max(ans, cnt);
            }
        }
    }

    cout << ans;

    return 0;
}
