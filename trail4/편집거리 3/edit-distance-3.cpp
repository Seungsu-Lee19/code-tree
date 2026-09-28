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
    
    int len_A = A.size();
    int len_B = B.size();

    vector<vector<int>> dp(
        len_A + 1,
        vector<int>(len_B + 1, INT_MAX - 1000)
    );

    for(int i = 0; i <= len_A; i++){
        dp[i][0] = i;
    }
    for(int i = 0; i <= len_B; i++){
        dp[0][i] = i;
    }

    for(int i = 1; i <= len_A; i++){
        for(int j = 1; j <= len_B; j++){
            if(A[i - 1] == B[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            else{
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
            }
        }
    }

    cout << dp[len_A][len_B];

    return 0;
}
