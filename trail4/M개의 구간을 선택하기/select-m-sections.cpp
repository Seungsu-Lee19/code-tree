#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int N, M;
int numbers[501];

int main() {
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> numbers[i];
    }

    // Please write your code here.

    // [l1, r1], [l2, r2] => r1 < l2
    // dp[i][j][2]
    // i번째 숫자까지 확인
    // j개의 구간을 만듦
    // 0 - 선택안함, 1 - 선택 함

    const int NEG = -1000000000;
    vector<vector<vector<int>>> dp(
        N + 1,
        vector<vector<int>>(
            M + 1,
            vector<int>(2, NEG)
        )
    );
    dp[0][0][0] = 0;

    for(int i = 1; i <= N; i++){
        dp[i][0][0] = 0;
        
        for(int j = 1; j <= M; j++){
            dp[i][j][1] = max(
                dp[i - 1][j][1] + numbers[i], // 기존 구간 이어서 붙히기
                dp[i - 1][j - 1][0] + numbers[i] // 새로운 구간 만들기
            );
            
            dp[i][j][0] = max(         // 선택 안함
                dp[i - 1][j][0], 
                dp[i - 1][j][1]
            );
        }
    }

    cout << max(dp[N][M][0], dp[N][M][1]);

    return 0;
}
