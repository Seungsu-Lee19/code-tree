#include <iostream>
#include <set>
#include <utility>

using namespace std;

const int MAX_N = 100000;

int n, m;
int k;

int main() {
    cin >> n >> m;

    set<pair<int, int>> se;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        se.insert({x, y});
    }

    for (int i = 0; i < m; i++) {
        cin >> k;

        auto it = se.lower_bound({k, 0});

        if(it == se.end()){
            cout << "-1 -1\n";
            continue;
        }

        auto [x, y] = *it;
        cout << x << " " << y << endl;
        se.erase(it);
    }

    // Please write your code here.

    return 0;
}
