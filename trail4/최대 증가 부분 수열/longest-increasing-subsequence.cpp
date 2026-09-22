#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int M[1000];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> M[i];
    }

    // Please write your code here.
    
    vector<int> dp(N, 1);
    for(int i = 1; i < N; i++){
        for(int j = 0; j <= i - 1; j++){
            if(M[j] < M[i]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    cout << *max_element(dp.begin(), dp.end());

    return 0;
}
