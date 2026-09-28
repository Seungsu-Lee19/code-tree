#include <iostream>
#include <string>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

int N;
string a, b;

int main() {
    cin >> N;
    cin >> a;
    cin >> b;

    // Please write your code here.
    // dp[i][j]
    // i번째 숫자를 b의 i번째 숫자랑 동일하게
    // j 번 반시계 돌림


    vector<vector<int>> dp(
        N + 1,
        vector<int>(10, INT_MAX)
    );

    dp[0][0] = 0;
    for(int i = 1; i <= N; i++){
        for(int j = 0; j < 10; j++){
            if(dp[i - 1][j] == INT_MAX) continue;

            int cur = (a[i - 1] - '0' + j) % 10;
            int target = (b[i - 1] - '0');

            int ccw = (target - cur + 10) % 10;
            int cw = (cur - target + 10) % 10;

            // 반시계 방향
            // i번째 숫자를 
            int next = (j + ccw) % 10;
            dp[i][next] = min(dp[i][next], dp[i - 1][j] + ccw);

            // 시계 방향
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + cw); 
        }
    }

    cout << *min_element(dp[N].begin(), dp[N].end());

    return 0;
}
