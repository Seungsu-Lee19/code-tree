#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int N;
int red[201];
int blue[201];

int main() {
    cin >> N;

    for (int i = 1; i <= 2 * N; i++) {
        cin >> red[i] >> blue[i];
    }

    // Please write your code here.
    // dp[i][j] => i는 시행 횟수, j는 red j개 골랐을 때 만들 수 있는 최대 합
    // dp[i][j] = dp[i - 1][j - 1] + red[i], dp[i - 1][j] + blue[i]

    vector<vector<int>> dp(2 * N + 1, vector<int>(N + 1, INT_MIN));
    dp[0][0] = 0;

    for(int i = 1; i <= 2 * N; i++){
        for(int j = 0; j <= N; j++){
            if(dp[i - 1][j] != INT_MIN){
                dp[i][j] = max(dp[i][j], dp[i - 1][j] + blue[i]);
            }

            if(dp[i - 1][j - 1] != INT_MIN && j >= 1){
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + red[i]);
            }
        }
    }
    cout << dp[2 * N][N];
    return 0;
}
