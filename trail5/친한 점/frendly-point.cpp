#include <iostream>
#include <set>
#include <utility>

using namespace std;

int n, m;

int main() {
    cin >> n >> m;

    int qx, qy;

    set<pair<int, int>> se;

    for (int i = 0; i < n; i++) {
        int x, y;

        cin >> x >> y;
        se.insert({x, y});
    }

    for (int i = 0; i < m; i++) {
        cin >> qx >> qy;

        auto it = se.lower_bound({qx, qy});
        if(it == se.end()) cout << "-1 -1\n";
        else {
            auto [x, y] = *it;
            cout << x << " " << y << endl;
        }
    }

    // Please write your code here.

    return 0;
}
