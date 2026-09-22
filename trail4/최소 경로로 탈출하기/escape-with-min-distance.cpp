#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

int n, m;
int a[100][100];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int bfs(){
    vector<vector<int>> visited(n, vector<int>(m));
    queue<pair<int, int>> q;
    
    q.push({0, 0});
    vector(0, 0);

    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();

        if(x == n - 1 && y == m - 1) return visited[x][y];

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

            if(visited[nx][ny] == 0 && a[nx][ny] == 1){
                visited[nx][ny] = visited[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    return -1;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    // Please write your code here.
    cout << bfs();

    return 0;
}
