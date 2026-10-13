#include <iostream>
#include <vector>

using namespace std;

int n, m;

vector<int> dp;
vector<vector<int>> child;

void dfs(int node){
    for(int c: child[node]){
        dp[c] += dp[node];
        dfs(c);
    }
}

int main() {
    cin >> n >> m;

    dp.resize(n + 1);
    child.resize(n + 1);

    int parent;
    for (int j = 1; j <= n; j++) {
        cin >> parent;
        if(parent != -1) child[parent].push_back(j);
    }

    int i, w;
    for (int j = 1; j <= m; j++) {
        cin >> i >> w;

        dp[i] += w;
    }

    dfs(1);

    for(int i = 1; i <= n; i++){
        cout << dp[i] << " ";
    }

    return 0;
}