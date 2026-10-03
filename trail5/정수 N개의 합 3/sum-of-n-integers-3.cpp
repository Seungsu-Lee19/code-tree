#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
int arr[501][501];

int main() {
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }

    // Please write your code here.
    vector<vector<int>> grid(
        n + 1,
        vector<int>(n + 1)
    );

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            grid[i][j] = grid[i - 1][j] + grid[i][j - 1] - grid[i - 1][j - 1] + arr[i][j];
        }
    }

    int ans = 0;
    for(int i = 1; i <= n - k + 1; i++){
        for(int j = 1; j <= n - k + 1; j++){
            int x2 = i + k - 1;
            int y2 = j + k - 1;
            ans = max(ans, grid[x2][y2] - grid[i - 1][y2] - grid[x2][j - 1] + grid[i - 1][j - 1]);
        }
    }

    cout << ans;

    return 0;
}
