#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int n, k, u, d;
int grid[8][8];

vector<int> idx;
int ans = 0;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void bfs(){
    queue<pair<int, int>> q;
    vector<vector<int>> visited(n, vector<int>(n));
    int cnt = 0;

    for(int i = 0; i < k; i++){
        int x = idx[i] / n;
        int y = idx[i] % n;
        q.push({x, y});
        visited[x][y] = 1;
    }

    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();
        cnt++;

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

            if(visited[nx][ny] == 0 && abs(grid[nx][ny] - grid[x][y]) >= u && abs(grid[nx][ny] - grid[x][y]) <= d){
                q.push({nx, ny});
                visited[nx][ny] = 1;
            }
        }
    }

    ans = max(ans, cnt);
}

void simul(int cnt, int cur){
    if(cnt == k){
        bfs();
        return;
    }

    for(int i = cur; i < n * n; i++){
        idx.push_back(i);
        simul(cnt + 1, i + 1);
        idx.pop_back();
    }
}

int main() {
    cin >> n >> k >> u >> d;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    simul(0, 0);
    cout << ans;

    return 0;
}
