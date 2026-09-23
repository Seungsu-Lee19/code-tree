#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 1000;

int N;
int M[MAX_N];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> M[i];
    }

    // Please write your code here.
    vector<int> dp(N, 1);

    for(int i = 1; i < N; i++){
        for(int j = 0; j <= i - 1; j++){
            if(M[i] < M[j]) dp[i] = max(dp[i], dp[j] +  1);
        }
    }

    cout << *max_element(dp.begin(), dp.end());

    return 0;
}
