#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

string A, B;

int main() {
    cin >> A;
    cin >> B;

    // Please write your code here.

    // dp[i][j][3]
    // A의 i번째 문자를
    // B의 j번째 문자로 변경
    // 넣기, 삭제, 변경
    
    vector<vector<int>> dp(
        A.size() + 1,
        vector<int>(B.size() + 1, INT_MAX - 1000)
    );

    for(int i = 0; i <= A.size(); i++){
        dp[i][0] = i;
    }

    for(int j = 0; j <= B.size(); j++){
        dp[0][j] = j;
    }


    for(int i = 1; i <= A.size(); i++){
        for(int j = 1; j <= B.size(); j++){
            if(A[i - 1] == B[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            else{
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]);
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]) + 1;
            }
        }
    }

    cout << dp[A.size()][B.size()];

    return 0;
}
