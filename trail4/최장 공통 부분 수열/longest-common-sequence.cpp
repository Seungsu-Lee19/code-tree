#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string A, B;

int main() {
    cin >> A;
    cin >> B;

    // Please write your code here.
    
    // d[i][j]
    // A의 i번째
    // B의 j번째

    vector<vector<int>> dp(
        A.size() + 1,
        vector<int>(B.size() + 1)
    );


    for(int i = 1; i <= A.size(); i++){
        for(int j = 1; j <= B.size(); j++){
            if(A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[A.size()][B.size()];

    return 0;
}
