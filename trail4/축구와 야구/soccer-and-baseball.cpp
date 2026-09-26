#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int soccer[1001];
int baseball[1001];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> soccer[i] >> baseball[i];
    }

    // Please write your code here.
    // dp[i][s][b] => i번째 학생을 선택했을 때, s또는 b에 넣음
    // dp[i][s][b] = if(s < 11) dp[i - 1][s][b] + s[i]
    //               if(b < 9) dp[i - 1][s][b] + b[i]
    //               if(s >= 11) dp[i - 1][s - 1][b] + s[i]
    //               if(b >= 9) dp[i - 1][s][b - 1] + b[i]

    vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(12, vector<long long>(10, -1)));
    dp[0][0][0] = 0;

    for(int i = 1; i <= n; i++){
        for(int s = 0; s <= 11; s++){
            for(int b = 0; b <= 9; b++){
                dp[i][s][b] = dp[i - 1][s][b];

                if(s >= 1 && dp[i - 1][s - 1][b] != -1) dp[i][s][b] = max(dp[i][s][b], dp[i - 1][s - 1][b] + soccer[i]);

                if(b >= 1 && dp[i - 1][s][b - 1] != -1) dp[i][s][b] = max(dp[i][s][b], dp[i - 1][s][b - 1] + baseball[i]);
            }
        }
    }

    cout << dp[n][11][9];

    return 0;
}
