#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int n;
int arr[301][301];

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }

    vector<vector<int>> sum(
        n + 1,
        vector<int>(n + 1)
    );
    int ans = INT_MIN;
   for (int top = 1; top <= n; top++) {

    vector<int> col(n + 1, 0);

    for (int bottom = top; bottom <= n; bottom++) {

        // top ~ bottom까지 각 열의 합
        for (int j = 1; j <= n; j++) {
            col[j] += arr[bottom][j];
        }

        // col[]에서 최대 연속 부분합
        int cur = col[1];
        int best = col[1];

        for (int j = 2; j <= n; j++) {
            cur = max(col[j], cur + col[j]);
            best = max(best, cur);
        }

        ans = max(ans, best);
    }
}
    cout << ans;

    return 0;
}