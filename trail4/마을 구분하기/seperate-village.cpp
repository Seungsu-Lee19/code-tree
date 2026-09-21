#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int cnt = 0;
int grid[25][25];
int visited[25][25];
vector<int> ans;
 

int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};

void dfs(int x, int y){
    visited[x][y] = 1;
    cnt++;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

        if(visited[nx][ny] == 0 && grid[nx][ny] == 1) dfs(nx, ny);
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(grid[i][j] == 1 && visited[i][j] == 0){
                cnt = 0;
                dfs(i, j);
                ans.push_back(cnt);
            }
        }
    }

    cout << ans.size() << endl;
    sort(ans.begin(), ans.end());
    for(int i : ans){
        cout << i << endl;
    }

    return 0;
}
