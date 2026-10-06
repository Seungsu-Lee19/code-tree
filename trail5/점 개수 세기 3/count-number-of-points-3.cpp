#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

const int MAX_N = 100000;
int n, q;

int main() {
    cin >> n >> q;

    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());

    int a, b;
    for (int i = 0; i < q; i++) {
        cin >> a >> b;

        auto left = lower_bound(vec.begin(), vec.end(), a);
        auto right = lower_bound(vec.begin(), vec.end(), b);

        cout << right - left + 1 << "\n";
    }

    // Please write your code here.

    return 0;
}
