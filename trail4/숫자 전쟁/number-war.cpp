#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int first_cards[1000];
int second_cards[1000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> first_cards[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> second_cards[i];
    }

    // Please write your code here.

    // dp[i][j] => first_player == i , second_player == j
    // if(f > s) dp[i][j] == max(dp[i][j + 1] + s, dp[i + 1][j + 1])
    // else      dp[i][j] == max(dp[i + 1][j], dp[i + 1][j + 1])
    
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));

    for(int i = n - 1; i >= 0; i--){
        for(int j = n - 1; j >= 0; j--){
            if(first_cards[i] > second_cards[j]) dp[i][j] = max(dp[i + 1][j + 1], dp[i][j + 1] + second_cards[j]);
            else if(first_cards[i] < second_cards[j]) dp[i][j] = max(dp[i + 1][j + 1], dp[i + 1][j]);
            else dp[i][j] = dp[i + 1][j + 1];
        }
    }

    cout << dp[0][0];

    return 0;
}
