#include <iostream>
#include <set>

using namespace std;

int n, m;
int arr;
int queries;

int main() {
    cin >> n >> m;

    set<int> se;
    for (int i = 0; i < n; i++) {
        cin >> arr;
        se.insert(arr);
    }

    for (int i = 0; i < m; i++) {
        cin >> queries;

        auto it = se.lower_bound(queries);

        if(it == se.end()) cout << "-1\n";
        else cout << *it << endl;
    }

    // Please write your code here.

    return 0;
}
