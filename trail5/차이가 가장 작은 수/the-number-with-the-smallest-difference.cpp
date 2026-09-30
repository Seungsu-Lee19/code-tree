#include <iostream>
#include <set>
#include <climits>
#include <algorithm>

using namespace std;

long long n, m;
long long arr;

int main() {
    cin >> n >> m;

    set<long long> se;
    long long ans = LLONG_MAX;

    for (int i = 0; i < n; i++) {
        cin >> arr;

        // 1. arr + m 이상인 값 중 가장 작은 값
        auto right = se.lower_bound(arr + m);

        if (right != se.end()) {
            ans = min(ans, *right - arr);
        }

        // 2. arr - m 이하인 값 중 가장 큰 값
        auto left = se.upper_bound(arr - m);

        if (left != se.begin()) {
            --left;
            ans = min(ans, arr - *left);
        }

        se.insert(arr);
    }

    if (ans == LLONG_MAX)
        cout << -1;
    else
        cout << ans;

    return 0;
}