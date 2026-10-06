#include <iostream>

#define MAX_N 400

using namespace std;

// 변수 선언
int n, k;
int board[MAX_N + 1][MAX_N + 1];
int s[MAX_N + 1][MAX_N + 1];
int ans = 0;

int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) cin >> board[i][j];

    // 배열의 누적합을 구합니다.
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            s[i][j] = s[i][j-1] + board[i][j];
    
    // 모든 중심에 대해 최댓값을 구합니다.
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) {
            // 중심이 (i, j)일 때의 숫자 합을 구합니다.
            int sum_all = 0;
            for(int r = i - k; r <= i + k; r++) {
                // r행일때 (j - c ~ j + c)열 까지의 부분합을 더해줍니다.
                int c = k - abs(i - r);

                // r행이 범위 안에 있을 경우 부분합을 더해줍니다.
                if(1 <= r && r <= n)
                    sum_all += s[r][min(j + c, n)] - s[r][max(j - c - 1, 0)];
            }
            
            ans = max(ans, sum_all);
        }
    
    // 정답을 출력합니다.
    cout << ans;
}
