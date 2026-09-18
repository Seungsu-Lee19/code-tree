#include <iostream>
#include <algorithm>

using namespace std;

int n;
int num[4][4];
int move_dir[4][4];
int r, c;
int ans = 0;

int dx[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int dy[9] = {0, 0, 1, 1, 1, 0, -1, -1, -1};

void back(int x, int y, int cnt){
    int cur_num = num[x][y];
    int cur_dir = move_dir[x][y];
    for(int i = 1; i <= n; i++){
        int nx = x + dx[cur_dir] * i;
        int ny = y + dy[cur_dir] * i;

        // cout << nx << " " << ny << endl;

        if(nx < 0 || ny < 0 || nx >= n || ny >= n) {
            ans = max(ans, cnt); 
            return;
        }
        if(num[nx][ny] > cur_num) back(nx, ny, cnt + 1);
    }

    return;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> num[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> move_dir[i][j];

    cin >> r >> c;

    // Please write your code here.
    back(r - 1, c - 1, 0);
    cout << ans;
    return 0;
}
