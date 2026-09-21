#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int n, m;
int a[100][100];

int visited[100][100] = {0, };

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void bfs(int sx, int sy){
    queue<pair<int, int>> q;

    q.push({sx, sy});
    visited[sx][sy] = 1;

    while(!q.empty()){
        auto [x, y] = q.front();
        
        if(x == n - 1 && y == m - 1) return;

        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

            if(a[nx][ny] == 1 && visited[nx][ny] == 0){
                q.push({nx, ny});
                visited[nx][ny] = 1;
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    // Please write your code here.
    bfs(0, 0);
    cout << visited[n - 1][m - 1];


    return 0;
}
