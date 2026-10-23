#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <iterator>

using namespace std;

int N, M;

vector<vector<int>> grid;
set<vector<pair<int, int>>> groups;
vector<vector<bool>> visited;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void dfs(int depth, vector<pair<int, int>>& selected){
    if(depth == 5){
        auto group = selected;
        sort(group.begin(), group.end());
        groups.insert(group);

        return;
    }

    for(int i = 0; i < depth; i++){
        auto [x, y] = selected[i];

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

            if(!visited[nx][ny]){
                visited[nx][ny] = true;
                selected.push_back({nx, ny});

                dfs(depth + 1, selected);

                visited[nx][ny] = false;
                selected.pop_back();
            }
        }
    }
}

int main() {
    cin >> N >> M;

    grid.resize(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    visited.resize(N, vector<bool>(M));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            vector<pair<int, int>> selected;
            selected.push_back({i, j});
            visited[i][j] = true;

            dfs(1, selected);

            visited[i][j] = false;
        }
    }

    int ans = -1000000;
    for(auto i = groups.begin(); i != groups.end(); ++i){
        for(auto j = next(i); j != groups.end(); ++j){
            int cnt = 0;

            for(auto [x1, y1]: *i){
                for(auto [x2, y2]: *j){
                    if(x1 == x2 && y1 == y2) cnt++;
                }
            }

            if(cnt == 2){
                int score = 0;

                for(auto [x1, y1]: *i) score += grid[x1][y1];
                for(auto [x2, y2]: *j) score += grid[x2][y2];

                ans = max(ans, score);
            }
        }
    }

    cout << ans;

    return 0;
}
