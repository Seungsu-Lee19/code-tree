#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, q;

int main() {
    cin >> n >> q;

    vector<int> efficiency(n);
    for (int i = 0; i < n; i++) {
        cin >> efficiency[i];
    }

    sort(efficiency.begin(), efficiency.end());

    int m;
    for (int i = 0; i < q; i++) {
        cin >> m;

        auto it = lower_bound(efficiency.begin(), efficiency.end(), m);

        if(*it != m) {
            cout << "0\n";
            continue;
        }

        int left = it - efficiency.begin();
        it++;
        int right = efficiency.end() - it;

        cout << left * right << "\n";
    }

    // Please write your code here.

    return 0;
}
