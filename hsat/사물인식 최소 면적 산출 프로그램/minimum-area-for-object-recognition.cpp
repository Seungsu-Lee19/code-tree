#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int N, K;
vector<vector<pair<int, int>>> points;
vector<vector<pair<int, int>>> used;

int ans = INT_MAX;


void dfs(int depth, int min_x, int max_x, int min_y, int max_y) {
    int rect = (max_x - min_x) * (max_y - min_y);
    
    if (depth == K) {
        ans = min(ans, rect);
        return;
    }

    if(rect > ans) return;

    int color = depth + 1;

    for (auto [x, y] : points[color]) {
        dfs(depth + 1, min(min_x, x), max(max_x, x), min(min_y, y), max(max_y, y));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    points.resize(K + 1);
    used.resize(K + 1);

    for (int i = 0; i < N; i++) {
        int x, y, k;
        cin >> x >> y >> k;
        points[k].push_back({x, y});
    }

    // Please write your code here.

    // 서로 다른색 K개를 포함하는 직사각형의 최소 넓이 구하기.
    // 각 points[k]에 대해 {x, y}를 추출해서 (maxX - minX + 1) * (maxY - minY + 1)
    // 
    dfs(0, INT_MAX, INT_MIN, INT_MAX, INT_MIN);
    cout << ans;

    return 0;
}
