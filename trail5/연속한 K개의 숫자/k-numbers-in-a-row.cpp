#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K, B;
int missing[100001];

int main() {
    cin >> N >> K >> B;

    vector<int> vec(N + 1);
    for(int i = 1; i <= N; i++) vec[i] = i;

    for (int i = 0; i < B; i++) {
        cin >> missing[i];
        vec[missing[i]] = 0;
    }

    // Please write your code here.
    int ans = B;

    for(int i = 1; i <= N - K + 1; i++){
        int cnt = 0;
        for(int j = i; j < i + K; j++){
            if(vec[j] == 0) cnt++;
        }

        ans = min(ans, cnt);
    }

    cout << ans;

    return 0;
}
