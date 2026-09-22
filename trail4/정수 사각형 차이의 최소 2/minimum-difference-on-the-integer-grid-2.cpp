#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;

int n;
int grid[100][100];
int dp[100][100];

int dx[2] = {0, 1};
int dy[2] = {1, 0};

int ans = 100;

bool check(int low, int high){
    if(grid[0][0] < low || grid[0][0] > high) return false;

    queue<pair<int, int>> q;
    vector<vector<int>> visited(n, vector<int>(n));

    q.push({0, 0});
    visited[0][0] = 0;

    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();

        if(x == n - 1 && y == n - 1) return true;

        for(int i = 0; i < 2; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

            if(grid[nx][ny] >= low && grid[nx][ny] <= high && visited[nx][ny] == 0){
                visited[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }

    return false;
}

int main() {
    cin >> n;

    int _min = 100;
    int _max = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            _min = min(_min, grid[i][j]);
            _max = max(_max, grid[i][j]);
        }
    }

    // Please write your code here.

    // (최대 - 최소)가 최소가 되도록
    int left = 0;
    int right = _max - _min;
    int ans = right;

    while(left <= right){
        int mid = (left + right) / 2;
        bool isMove = false;

        for(int low = _min; low <= _max - mid; low++){ // [r, r + mid] => r은 _min부터 min(r + mid, _max);
            if(check(low, low + mid)){
                isMove = true;
            }

            if(isMove) break;
        }

        if(isMove){
            right = mid - 1;
            ans = mid;
        }
        else{
            left = mid + 1;
        }
    }

    cout << ans;

    return 0;
}
