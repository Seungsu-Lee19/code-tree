
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N, M;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    vector<string> dna(N);

    for (int i = 0; i < N; i++) {
        cin >> dna[i];
    }

    int total = 1 << N;

    // valid[mask] : 선택된 문자열들을 하나로 합칠 수 있는가?
    vector<bool> valid(total, true);

    for (int mask = 1; mask < total; mask++) {
        for (int j = 0; j < M; j++) {
            char c = '.';

            for (int i = 0; i < N; i++) {
                if (!(mask & (1 << i))) continue;
                if (dna[i][j] == '.') continue;

                if (c == '.') {
                    c = dna[i][j];
                }
                else if (c != dna[i][j]) {
                    valid[mask] = false;
                    break;
                }
            }

            if (!valid[mask]) break;
        }
    }

    // dp[mask] : 선택된 문자열을 커버하는 최소 그룹 수
    vector<int> dp(total, N + 1);

    dp[0] = 0;

    for (int mask = 1; mask < total; mask++) {

        // 하나의 그룹으로 합칠 수 있는 경우
        if (valid[mask]) {
            dp[mask] = 1;
            continue;
        }

        // mask의 모든 부분집합 탐색
        for (int sub = (mask - 1) & mask;
             sub > 0;
             sub = (sub - 1) & mask) {

            if (valid[sub]) {
                dp[mask] = min(dp[mask],
                               dp[mask ^ sub] + 1);
            }
        }
    }

    cout << dp[total - 1];

    return 0;
}
