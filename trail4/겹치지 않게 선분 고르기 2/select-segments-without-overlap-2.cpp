#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int n;

int main() {
    cin >> n;

    vector<pair<int, int>> line;
    int x1, x2;
    for (int i = 0; i < n; i++) {
        cin >> x1 >> x2;
        line.push_back({x1, x2});
    }

    // Please write your code here.
    sort(line.begin(), line.end());
    vector<int> dp(n, 1);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            // if(i == j) continue;

            if(line[i].first > line[j].second) dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    cout << *max_element(dp.begin(), dp.end());

    return 0;
}
