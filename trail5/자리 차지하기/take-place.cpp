#include <iostream>
#include <set>

using namespace std;

int N, M;
int a[100000];

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    // 현재 비어 있는 의자
    set<int> se;

    for (int i = 1; i <= M; i++) {
        se.insert(i);
    }

    int ans = 0;

    for (int i = 0; i < N; i++) {

        // a[i]보다 큰 첫 번째 의자
        auto it = se.upper_bound(a[i]);

        // a[i] 이하인 빈 의자가 하나도 없음
        if (it == se.begin()) {
            break;
        }

        // a[i] 이하인 의자 중 가장 큰 의자
        --it;

        // 해당 의자에 앉음
        se.erase(it);

        ans++;
    }

    cout << ans << '\n';

    return 0;
}