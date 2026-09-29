#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

string s;
string t;

int main() {
    cin >> s;
    cin >> t;

    // Please write your code here.

    vector<vector<int>> dp(
        s.size() + 1,
        vector<int>(t.size() + 1, INT_MIN)
    );
    // dp[0][0] = 0;

    for(int i = 0; i <= s.size(); i++){
        dp[i][0] = i;
    }
    for(int i = 0; i <= t.size(); i++){
        dp[0][i] = i;
    }

    for(int i = 1; i <= s.size(); i++){
        for(int j = 1; j <= t.size(); j++){
            if(s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
        }
    }
    cout << dp[s.size()][t.size()];

    return 0;
}
