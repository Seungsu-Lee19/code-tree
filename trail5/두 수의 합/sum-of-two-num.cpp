#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int N;
    long long K;

    cin >> N >> K;

    unordered_map<long long, long long> cnt;

    long long ans = 0;

    for(int i = 0; i < N; i++){
        long long x;
        cin >> x;

        // x와 더해서 K가 되어야 하는 값
        long long target = K - x;

        // 앞에서 target이 나온 횟수만큼
        // 현재 x와 새로운 쌍을 만들 수 있음
        ans += cnt[target];

        // 현재 x를 이후 숫자들을 위해 저장
        cnt[x]++;
    }

    cout << ans;

    return 0;
}