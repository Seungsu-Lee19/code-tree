#include <iostream>
#include <vector>

using namespace std;

int n;

vector<vector<int>> child;
vector<int> value;
vector<int> dp;

void dfs(int node){
    for(int c: child[node]){
        dfs(c);
    }

    dp[node] = value[node];
    for(int c: child[node]){
        if(dp[c] > 0) dp[node] += dp[c];
    }
}

int main() {
    cin >> n;

    child.resize(n + 1);
    value.resize(n + 1);
    dp.resize(n + 1);

    int t, a, p;
    for (int i = 2; i <= n; i++) {
        cin >> t >> a >> p;

        child[p].push_back(i);
        value[i] = (t == 1)? a: -a;
    }

    dfs(1);
    cout << dp[1];
    return 0;
}