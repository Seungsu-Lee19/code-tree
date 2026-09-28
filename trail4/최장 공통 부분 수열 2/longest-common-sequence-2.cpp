#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string A;
string B;

int main() {
    cin >> A;
    cin >> B;

    // Please write your code here.

    vector<vector<int>> dp(
        A.size() + 1,
        vector<int>(B.size() + 1)
    );

    for(int i = 1; i <= A.size(); i++){
        for(int j = 1; j <= B.size(); j++){
            if(A[i - 1] == B[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else{
                dp[i][j] = max(
                    dp[i - 1][j],
                    dp[i][j - 1]
                );
            }
        }
        // cout << A[*max_element(dp[1].begin(), dp[1].end())];
    }

    string answer;
    int i = A.size();
    int j = B.size();

    while(i > 0 && j > 0){

        if(A[i - 1] == B[j - 1]){
            answer.push_back(A[i - 1]);
            i--;
            j--;
        }
        else{
            if(dp[i - 1][j] > dp[i][j - 1]){
                i--;
            }
            else{
                j--;
            }
        }
    }

    reverse(answer.begin(), answer.end());

    cout << answer;

    // for(int i = 1; i <= A.size(); i++){
    //     for(int j = 1; j <= B.size(); j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    // cout << dp[A.size()][B.size()];

    return 0;
}
