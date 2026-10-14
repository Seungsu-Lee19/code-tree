#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int N;

vector<vector<int>> colors;
vector<pair<int, int>> del;

int ans = 0;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int bfs(int sx, int sy, vector<vector<int>>& garage, vector<vector<bool>>& visited){
    queue<pair<int, int>> q;

    q.push({sx, sy});
    visited[sx][sy] = 1;

    int minX = sx;
    int maxX = sx;
    int minY = sy;
    int maxY = sy;

    int cnt = 1;

    int color = garage[sx][sy];
    del.push_back({sx, sy});
    
    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 3 * N - N || ny < 0 || nx >= 3 * N || ny >= N) continue;

            if(garage[nx][ny] == color && visited[nx][ny] == false){
                visited[nx][ny] = true;
                q.push({nx, ny});
                del.push_back({nx, ny});

                minX = min(minX, nx);
                minY = min(minY, ny);
                maxX = max(maxX, nx);
                maxY = max(maxY, ny);

                cnt++;
            }
        }
    }

    return cnt + (maxX - minX + 1) * (maxY - minY + 1);
}

void gravity(vector<vector<int>>& garage){
    for(auto [x, y]: del){
        garage[x][y] = 0;
    }

    vector<int> row(N, 3 * N - 1);
    for(int j = 0; j < N; j++){
        for(int i = 3 * N - 1; i >= 2 * N; i--){
            if(garage[i][j] == 0){
                int i_idx = i;
                for(int k = i_idx - 1; k >= 0; k--){
                    if(garage[k][j] != 0){
                        garage[i_idx][j] = garage[k][j];
                        garage[k][j] = 0;
                        i_idx--;
                    }
                }
            }
        }
    }

    del.clear();
}

void dfs(int depth, int score, vector<vector<int>>& garage){
    if(depth == 3){
        ans = max(ans, score);
        return;
    }

    // visited_temp = visited;
    vector<vector<bool>> visited(
        3 * N,
        vector<bool> (N)
    );
    vector<vector<int>> garage_temp = garage;
    for (int i = 3 * N - 1; i >= 3 * N - N; i--) {
        for (int j = 0; j < N; j++) {
            if(visited[i][j] == 0){
                int s = bfs(i, j, garage, visited);
                
                if(depth < 2) gravity(garage);
                else del.clear();
                
                dfs(depth + 1, score + s, garage);
                garage = garage_temp;
            }
        }
    }
}

int main() {
    cin >> N;

    colors.resize(3 * N, vector<int>(N));
    for (int i = 0; i < 3 * N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> colors[i][j];
        }
    }

    // Please write your code here.

    // 색상 하나 고르고 -> 제거 -> 드랍 다운 -> 선택 반복
    // 경우에 수는 (n x n)에 있는 색의 수 
    // 드랍 다운 후 색의 수
    // 드랍 다운 후 색의 수
    // 최대 경우의 수는 (n * n) * (n * n) * (n * n) 약 11,000,000

    dfs(0, 0, colors);
    cout << ans;

    return 0;
}
