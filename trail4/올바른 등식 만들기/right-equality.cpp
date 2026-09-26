#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> a(N);

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    // dp[i][v + 20]
    // i번째 숫자까지 사용했을 때 합이 v가 되는 경우의 수
    vector<vector<long long>> dp(N, vector<long long>(41, 0));

    // 첫 번째 숫자
    if (a[0] <= 20) {
        dp[0][a[0] + 20]++;
        dp[0][-a[0] + 20]++;
    }

    for (int i = 1; i < N; i++) {
        for (int v = -20; v <= 20; v++) {

            if (dp[i - 1][v + 20] == 0)
                continue;

            int plus = v + a[i];
            int minus = v - a[i];

            if (plus >= -20 && plus <= 20) {
                dp[i][plus + 20] += dp[i - 1][v + 20];
            }

            if (minus >= -20 && minus <= 20) {
                dp[i][minus + 20] += dp[i - 1][v + 20];
            }
        }
    }

    cout << dp[N - 1][M + 20];

    return 0;
}