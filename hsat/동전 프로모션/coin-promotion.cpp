#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <unordered_map>

using namespace std;

int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    vector<int> ac;
    vector<int> bc;

    vector<int> dp(m + 1, INT_MAX);
    unordered_map<int, vector<int>> coin;

    for (int i = 0; i < n; i++) {
        int c;
        char t;
        cin >> t >> c;

        if(t == 'A') ac.push_back(c);
        else bc.push_back(c);
    }


    // Please write your code here.
    dp[0] = 0;

    for(int i = 0; i < ac.size(); i++){
        for(int money = 1; money <= m; money++){
            int v = money - ac[i];

            if(v < 0) continue;
            if(dp[v] == INT_MAX) continue;
            
            dp[money] = min(dp[money], dp[v] + 1);
        }
    }
        
    for(int i = 0; i < bc.size(); i++){
        for(int money = m; money >= 0; money--){
            int v = money - bc[i];

            if(v < 0) continue;
            if(dp[v] == INT_MAX) continue;
            
            dp[money] = min(dp[money], dp[v] + 1);
        }
    }

    if(dp[m] == INT_MAX) cout << -1;
    else cout << dp[m];

    

    return 0;
}
