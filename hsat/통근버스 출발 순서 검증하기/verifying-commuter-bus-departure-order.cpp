#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> sequence;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    sequence.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> sequence[i];
    }

    // Please write your code here.
    // dp[i][j][k]
    // i < j < k
    // ai < aj, ai > ak

    int ans = 0;
    for(int i = 0; i < N - 1; i++){
        int upper = 0;
        for(int j = i + 1; j < N; j++){
            if(sequence[i] < sequence[j]) upper++;
            else if(sequence[i] > sequence[j]) ans += upper;
        }
    }

    cout << ans;

    return 0;
}
