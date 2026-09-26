#include <iostream>
#include <vector>
#include <string>

using namespace std;

const long long MOD = 1000000007;

int main() {
    string N;
    cin >> N;

    int n = N.size();

    // dp[i][r][tight]
    // i     : 앞에서부터 i자리까지 결정
    // r     : 지금까지 만든 수를 3으로 나눈 나머지
    // tight : 1이면 지금까지 N과 동일
    //         0이면 이미 N보다 작음
    vector<vector<vector<long long>>> dp(
        n + 1,
        vector<vector<long long>>(3, vector<long long>(2, 0))
    );

    // 아직 아무 자리도 선택하지 않음
    // 만든 값은 0이므로 나머지 0
    // 아직 N과 동일한 상태
    dp[0][0][1] = 1;

    for (int i = 0; i < n; i++) {

        for (int r = 0; r < 3; r++) {

            for (int tight = 0; tight <= 1; tight++) {

                if (dp[i][r][tight] == 0)
                    continue;

                int limit;

                if (tight == 1)
                    limit = N[i] - '0';
                else
                    limit = 9;

                for (int d = 0; d <= limit; d++) {

                    // 3, 6, 9가 들어간 숫자는
                    // "박수를 치지 않는 수"가 아니므로 제외
                    if (d == 3 || d == 6 || d == 9)
                        continue;

                    int nextR = (r * 10 + d) % 3;

                    int nextTight = 0;

                    if (tight == 1 && d == N[i] - '0')
                        nextTight = 1;

                    dp[i + 1][nextR][nextTight]
                        = (dp[i + 1][nextR][nextTight]
                           + dp[i][r][tight]) % MOD;
                }
            }
        }
    }

    // 박수를 치지 않는 수
    // = 3,6,9가 없고
    //   3의 배수가 아닌 수
    //
    // 따라서 나머지가 1 또는 2인 경우만 센다.
    long long noClap = 0;

    for (int tight = 0; tight <= 1; tight++) {
        noClap = (noClap + dp[n][1][tight]) % MOD;
        noClap = (noClap + dp[n][2][tight]) % MOD;
    }

    // N이 최대 10만 자리이므로
    // N 자체를 정수형으로 바꿀 수 없음.
    // N % MOD를 문자열로 계산
    long long nMod = 0;

    for (char c : N) {
        nMod = (nMod * 10 + (c - '0')) % MOD;
    }

    // 전체 1~N 중 박수를 치지 않는 수를 제외
    long long ans = (nMod - noClap + MOD) % MOD;

    cout << ans << '\n';

    return 0;
}