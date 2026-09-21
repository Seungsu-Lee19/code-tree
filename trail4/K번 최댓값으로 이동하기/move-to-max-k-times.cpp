#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <tuple>

using namespace std;

int n, k;
int r, c;
int grid[100][100];

vector<vector<bool>> visited;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool bfs(int sx, int sy, int fx, int fy){
    queue<pair<int, int>> q;
    q.push({sx, sy});
    visited[sx][sy] = true;

    int value = grid[sx][sy];
    
    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();

        if(x == fx && y == fy) return true;

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

            if(visited[nx][ny] == false && grid[nx][ny] < value){
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }

    return false;
}

int main() {
    cin >> n >> k;

    priority_queue<tuple<int, int, int>> pq;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            pq.push({grid[i][j], -i, -j});
        }
    }

    cin >> r >> c;
    r--;
    c--;

    // Please write your code here.

    visited.resize(n, vector<bool>(n, false));

    for(int i = 0; i < k; i++){
        priority_queue<tuple<int, int, int>> temp = pq;
        bool isCanMove = false;
        int v, x, y;

        while(!temp.empty()){
            tie(v, x, y) = temp.top();
            temp.pop();

            x = -x;
            y = -y;


            visited.assign(n, vector<bool>(n, false));
            if(v < grid[r][c]){
                isCanMove = bfs(r, c, x, y);
                // cout << "\n" << r << " " << c << " : " << grid[r][c] << " => " << v << endl;
                // cout << x << " " << y << " : " << isCanMove << endl;
                if(isCanMove) break;
            }
        }


        if(isCanMove){
            r = x;
            c = y;
            pq = temp;
        }
        else break;
    }

    cout << r + 1 << " " << c + 1;

    return 0;
}
