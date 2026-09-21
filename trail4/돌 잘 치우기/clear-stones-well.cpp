#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, k, m;

vector<vector<int>> grid;
vector<pair<int, int>> start;
vector<pair<int, int>> rock;
vector<int> idx;

int ans = 0;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void bfs(){
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(n, vector<bool>(n));
    vector<vector<int>> temp = grid;

    int cnt = 0;

    for(int i = 0; i < m; i++){
        auto [x, y] = rock[idx[i]];
        temp[x][y] = 0;
    }

    for(auto [x, y] : start){
        q.push({x, y});
        visited[x][y] = true;
    }

    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();

        cnt++;

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

            if(visited[nx][ny] == false && temp[nx][ny] == 0){
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }

    ans = max(ans, cnt);
}

void simul(int cnt, int cur){
    if(cnt == m){
        bfs();
        return;
    }

    for(int i = cur; i < rock.size(); i++){
        idx[cnt] = i;
        simul(cnt + 1, i + 1);
    }
}

int main() {
    cin >> n >> k >> m;

    grid.resize(n, vector<int>(n));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];

            if(grid[i][j]) rock.push_back({i, j});
        }
    }

    int r, c;
    for (int i = 0; i < k; i++) {
        cin >> r >> c;
        start.push_back({r - 1, c - 1});
    }

    // Please write your code here.

    idx.resize(m);

    simul(0, 0);

    cout << ans;

    return 0;
}
