#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k;
char grid[1001][1001];

int main() {
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<vector<int>>> sum(
        n + 1,
        vector<vector<int>>(
            m + 1,
            vector<int>(3)
        )
    );
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for(int k = 0; k < 3; k++){
                sum[i][j][k] = sum[i - 1][j][k] + sum[i][j - 1][k] - sum[i - 1][j - 1][k];
                if(grid[i][j] - 'a' == k) sum[i][j][k]++;
            }
            
            // sum[i][j][grid[i][j] - 'a'] = sum[i - 1][j][grid[i][j] - 'a'] + sum[i][j - 1][grid[i][j] - 'a'] - sum[i - 1][j - 1][grid[i][j] - 'a'] + 1;
            // sum[i][j][grid[i][j] - 'a'] = sum[i - 1][j][grid[i][j] - 'a'] + sum[i][j - 1][grid[i][j] - 'a'] - sum[i - 1][j - 1][grid[i][j] - 'a'] + 1;
        }
    }

    for (int i = 0; i < k; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;

        int value1 = sum[r2][c2][0] - sum[r1 - 1][c2][0] - sum[r2][c1 - 1][0] + sum[r1 - 1][c1 - 1][0];
        int value2 = sum[r2][c2][1] - sum[r1 - 1][c2][1] - sum[r2][c1 - 1][1] + sum[r1 - 1][c1 - 1][1];
        int value3 = sum[r2][c2][2] - sum[r1 - 1][c2][2] - sum[r2][c1 - 1][2] + sum[r1 - 1][c1 - 1][2];

        cout << value1 << " " << value2 << " " << value3 << endl;
    }

    // Please write your code here.

    return 0;
}
