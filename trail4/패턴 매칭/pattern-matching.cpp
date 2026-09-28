#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string s;
string p;

int main() {
    cin >> s;
    cin >> p;

    // Please write your code here.
    int lenS = s.size();
    int lenP = p.size();

    int s_idx = 0;
    int p_idx = 0;

    while(s_idx < lenS && p_idx < lenP){
        if(p[p_idx] == '.'){
            s_idx++;
            p_idx++;
        }
        else if(p[p_idx] == '*'){
            if(p[p_idx - 1] == '.'){
                s_idx++;
            }
            else if(s[s_idx] == p[p_idx - 1]){
                s_idx++;
            }
            else {
                p_idx++;
            }
        }
        else{
            if(s[s_idx] == p[p_idx]){
                s_idx++;
                p_idx++;
            }
            else{
                p_idx++;
            }
        }
    }

    // cout << s_idx << " " << p_idx;

    if(s_idx == s.size()) cout << "true";
    else cout << "false";

    // vector<vector<int>> dp(
    //     lenS + 1,
    //     vector<int> (lenP + 1, -1)
    // );
    // dp[0][0] = 0;

    // for(int i = 1; i <= lenS; i++){
    //     for(int j = 1; j <= lenP; j++){
    //         if(p[j - 1] == '.') {
    //             dp[i][j] = dp[i - 1][j - 1] + 1;
    //         }
    //         else if(p[j - 1] == '*'){
    //             if(p[j - 2] == s[i]){
    //                 dp[i][j] = dp[i - 1][j - 1] + 1;
    //             }
    //             dp[i][j] = dp[i - 1]
    //         }
    //         else{

    //         }
    //     }
    // }

    return 0;
}
