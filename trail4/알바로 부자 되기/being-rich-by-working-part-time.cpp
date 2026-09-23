#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int s[1000], e[1000], p[1000];

int main() {
    cin >> N;

    vector<int> dp(N);
    for (int i = 0; i < N; i++) {
        cin >> s[i] >> e[i] >> p[i];
        dp[i] = p[i];
    }

    // Please write your code here.

    for(int i = 1; i < N; i++){
        for(int j = 0; j < i; j++){
            if(e[j] < s[i]) dp[i] = max(dp[i], dp[j] + p[i]);
        }
    }

    cout << *max_element(dp.begin(), dp.end());

    return 0;
}
