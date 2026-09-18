#include <iostream>
#include <vector>
#include <utility>
#include <climits>
#include <algorithm>

using namespace std;

int n, m;
int ans = INT_MAX;

vector<pair<int, int>> grid;
vector<int> idx;

void calc(){
    int dist = 0;
    for(int i = 0; i < m - 1; i++){
        int idx1 = idx[i];
        auto [x1, y1] = grid[idx1];

        for(int j = i + 1; j < m; j++){
            int idx2 = idx[j];
            auto [x2, y2] = grid[idx2];

            dist = max(dist, (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        }
    }

    ans = min(ans, dist);
}

void back(int cnt, int start){
    if(cnt == m){
        calc();
        return;
    }

    for(int i = start; i < n; i++){
        idx.push_back(i);
        back(cnt + 1, i + 1);
        idx.pop_back();
    }
}

int main() {
    cin >> n >> m;

    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        grid.push_back({x, y});
    }

    // Please write your code here.
    back(0, 0);
    cout << ans;

    return 0;
}
