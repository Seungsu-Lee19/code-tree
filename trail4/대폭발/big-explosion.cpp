#include <iostream>
#include <cmath>
#include <utility>
#include <vector>

using namespace std;

int n, m, r, c;

int grid[101][101] = {0, };

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void bomb(int x, int y, int dist){
    for(int k = 0; k < 4; k++){
        int nx = x + (dx[k] * dist);
        int ny = y + (dy[k] * dist);

        if(nx < 1 || ny < 1 || nx > n || ny > n) continue;

        grid[nx][ny] = 1;
    }
}

int main() {
    cin >> n >> m >> r >> c;

    // Please write your code here.
    grid[r][c] = 1;


    for(int t = 1; t <= m; t++){
        vector<pair<int, int>> v;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(grid[i][j]) v.push_back({i, j});
            }
        }

        for(auto p : v){
            bomb(p.first, p.second, 1 << (t - 1));
        }
    }
    
    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= n; j++){
    //         cout << grid[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    int cnt = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(grid[i][j]) cnt++;
        }
    }

    cout << cnt;

    return 0;
}
