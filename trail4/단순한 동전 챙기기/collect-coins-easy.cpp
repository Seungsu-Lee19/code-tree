#include <iostream>
#include <vector>
#include <utility>
#include <climits>
#include <algorithm>
#include <tuple>

using namespace std;

int N;
// char grid[20][20];
vector<tuple<int, int, int>> grid;
pair<int, int> start, finish;
vector<int> idx;

int ans = INT_MAX;

void back(int cnt, int cur){
    if(cnt == 3){
        auto [sx, sy] = start;
        auto [id, ex, ey] = grid[idx[0]];

        int move = abs(sx - ex) + abs(sy- ey);
        sx = ex;
        sy = ey;

        for(int i = 1; i < 3; i++){
            tie(id, ex, ey) = grid[idx[i]];

            move = move + abs(sx - ex) + abs(sy- ey);

            sx = ex;
            sy = ey;
        }
        tie(ex, ey) = finish;

        move = move + abs(sx - ex) + abs(sy- ey);
        ans = min(ans, move);

        return;
    }

    for(int i = cur; i < grid.size(); i++){
        idx.push_back(i);
        back(cnt + 1, i + 1);
        idx.pop_back();
    }
}

int main() {
    cin >> N;

    char c;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++) {
            cin >> c;
            if(c == '.') continue;
            else if(c == 'S') start = {i, j};
            else if(c == 'E') finish = {i, j};
            else grid.push_back({c - '0', i, j});
        }
    }
    // Please write your code here.
    sort(grid.begin(), grid.end());
    back(0, 0);
    if(ans == INT_MAX) cout << -1;
    else cout << ans;

    return 0;
}
