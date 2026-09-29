#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int a[1001];
int b[1001];

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }

    // Please write your code here.
    
    vector<vector<int>> dp(
        n + 2,
        vector<int>(m + 2)
    );

    for(int i = n; i >= 1; i--){
        for(int j = m; j >= 1; j--){
            if(a[i] == b[j]) dp[i][j] = dp[i + 1][j + 1] + 1;
            else dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
        }
    }

    vector<int> posA(1001, -1);
    vector<int> posB(1001, -1);

    for(int i = 1; i <= n; i++) {
        posA[a[i]] = i;
    }

    for(int i = 1; i <= m; i++) {
        posB[b[i]] = i;
    }

    vector<int> answer;

    // 현재부터 찾아야 할 위치
    int ai = 1;
    int bi = 1;

    // 앞으로 뽑아야 할 LCS의 길이
    int remain = dp[1][1];

    while(remain > 0) {

        // 사전순으로 가장 작은 숫자부터 확인
        for(int x = 1; x <= 1000; x++) {

            int pa = posA[x];
            int pb = posB[x];

            // 둘 중 한 수열에 x가 없는 경우
            if(pa == -1 || pb == -1) continue;

            // 이미 지나간 위치에 있는 경우
            if(pa < ai || pb < bi) continue;

            // x를 지금 선택해도
            // 최장 길이 remain을 완성할 수 있는가?
            if(dp[pa + 1][pb + 1] == remain - 1) {

                answer.push_back(x);

                // x 이후부터 다음 숫자를 찾음
                ai = pa + 1;
                bi = pb + 1;

                remain--;

                // 가장 작은 가능한 x를 찾았으므로 종료
                break;
            }
        }
    }

    for(int x : answer) {
        cout << x << " ";
    }

    return 0;
}
