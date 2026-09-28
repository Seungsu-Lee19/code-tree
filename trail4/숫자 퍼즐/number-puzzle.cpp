#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    long long K;

    cin >> N >> M >> K;

    const long long LIMIT = 1000000001LL;

    // dp[len][sum][minValue]
    //
    // 앞으로 len개의 숫자를 골라야 하고
    // 숫자들의 합이 sum이어야 하며
    // 각 숫자는 minValue 이상이어야 할 때
    // 가능한 비내림차순 수열의 개수

    vector<vector<vector<long long>>> dp(
        N + 1,
        vector<vector<long long>>(
            M + 1,
            vector<long long>(M + 2, 0)
        )
    );

    // 숫자를 0개 골라서 합 0을 만드는 방법은 1개
    for(int minValue = 1; minValue <= M + 1; minValue++) {
        dp[0][0][minValue] = 1;
    }

    // DP 채우기
    for(int len = 1; len <= N; len++) {
        for(int sum = 0; sum <= M; sum++) {

            // 큰 최소값부터 내려와야 함
            for(int minValue = M; minValue >= 1; minValue--) {

                // minValue를 사용하지 않는 경우
                // -> 모든 숫자가 minValue + 1 이상
                dp[len][sum][minValue]
                    = dp[len][sum][minValue + 1];

                // minValue를 하나 사용하는 경우
                if(sum >= minValue) {
                    dp[len][sum][minValue] +=
                        dp[len - 1][sum - minValue][minValue];
                }

                // 너무 큰 경우의 수는 잘라줌
                dp[len][sum][minValue]
                    = min(dp[len][sum][minValue], LIMIT);
            }
        }
    }

    // K번째 수열 자체가 존재하지 않는 경우
    if(dp[N][M][1] < K) {
        cout << -1;
        return 0;
    }

    vector<int> answer;

    int remainCount = N;
    int remainSum = M;
    int minValue = 1;

    while(remainCount > 0) {

        // 현재 자리에 들어갈 숫자를 작은 것부터 확인
        for(int x = minValue; x <= remainSum; x++) {

            // x를 현재 숫자로 선택했다고 가정
            //
            // 이후에는
            // remainCount - 1개를 더 골라야 하고
            // 합은 remainSum - x
            // 다음 숫자는 x 이상이어야 함

            long long cnt = 0;

            if(remainSum >= x) {
                cnt = dp[remainCount - 1][remainSum - x][x];
            }

            // x로 시작하는 수열들을 전부 건너뜀
            if(K > cnt) {
                K -= cnt;
            }

            // K번째 수열이 x로 시작하는 그룹 안에 있음
            else {
                answer.push_back(x);

                remainCount--;
                remainSum -= x;
                minValue = x;

                break;
            }
        }
    }

    for(int x : answer) {
        cout << x << " ";
    }

    return 0;
}