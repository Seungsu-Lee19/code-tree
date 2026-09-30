#include <iostream>
#include <set>

using namespace std;

int n, m;
int sequence;
int query;

int main() {
    cin >> n >> m;

    set<int> se;

    for (int i = 0; i < n; i++) {
        cin >> sequence;
        se.insert(sequence);
    }

    for (int i = 0; i < m; i++) {
        cin >> query;

        // query보다 큰 첫 번째 값
        auto it = se.upper_bound(query);

        // query 이하인 값이 하나도 없음
        if (it == se.begin()) {
            cout << -1 << '\n';
            continue;
        }

        // query 이하인 값 중 가장 큰 값
        --it;

        cout << *it << '\n';

        // 사용한 값 삭제
        se.erase(it);
    }

    return 0;
}