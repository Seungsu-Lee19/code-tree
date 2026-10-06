#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;

    vector<pair<int, int>> points(n);

    vector<int> xs;
    vector<int> ys;

    // 점 입력
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        points[i] = {x, y};

        xs.push_back(x);
        ys.push_back(y);
    }

    // 좌표 압축을 위해 정렬
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());

    // 문제에서 점의 위치는 서로 다르지만
    // x좌표나 y좌표는 서로 같을 수 있으므로 중복 제거
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());

    int X = xs.size();
    int Y = ys.size();

    // 1-based 좌표를 사용하기 위해 +1
    vector<vector<int>> sum(
        X + 1,
        vector<int>(Y + 1, 0)
    );

    // 점을 압축된 좌표에 표시
    for (auto [x, y] : points) {
        int nx = lower_bound(xs.begin(), xs.end(), x) - xs.begin() + 1;
        int ny = lower_bound(ys.begin(), ys.end(), y) - ys.begin() + 1;

        sum[nx][ny]++;
    }

    // 2차원 누적합
    for (int i = 1; i <= X; i++) {
        for (int j = 1; j <= Y; j++) {
            sum[i][j]
                += sum[i - 1][j]
                 + sum[i][j - 1]
                 - sum[i - 1][j - 1];
        }
    }

    // 쿼리 처리
    while (q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        // x1 이상인 첫 x좌표
        int cx1 = lower_bound(xs.begin(), xs.end(), x1) - xs.begin() + 1;

        // x2 이하인 마지막 x좌표
        int cx2 = upper_bound(xs.begin(), xs.end(), x2) - xs.begin();

        // y1 이상인 첫 y좌표
        int cy1 = lower_bound(ys.begin(), ys.end(), y1) - ys.begin() + 1;

        // y2 이하인 마지막 y좌표
        int cy2 = upper_bound(ys.begin(), ys.end(), y2) - ys.begin();

        // 해당 범위에 점이 아예 없는 경우
        if (cx1 > cx2 || cy1 > cy2) {
            cout << 0 << '\n';
            continue;
        }

        int ans =
              sum[cx2][cy2]
            - sum[cx1 - 1][cy2]
            - sum[cx2][cy1 - 1]
            + sum[cx1 - 1][cy1 - 1];

        cout << ans << '\n';
    }

    return 0;
}