#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int N, M;
vector<vector<int>> grid;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int bfs(){
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(N, vector<bool>(M));

    q.push({0, 0});
    visited[0][0] = true;

    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

            if(visited[nx][ny] == false && grid[nx][ny] == 0){
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }

    int cnt = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(visited[i][j]){
                for(int k = 0; k < 4; k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

                    if(grid[nx][ny]){
                        grid[nx][ny] = 0;
                        cnt++;
                    }
                }
            }
        }
    }

    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(grid[i][j]) return -1;
        }
    }

    return cnt;
}

int main() {
    cin >> N >> M;

    int v;
    grid.resize(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> v;
            grid[i][j] = v;
        }
    }

    // Please write your code here.
    int t = 0;
    while(true){
        t++;

        int cnt = bfs();
        if(cnt != -1){
            cout << t << " " << cnt;
            break;
        }
    }

    return 0;
}
