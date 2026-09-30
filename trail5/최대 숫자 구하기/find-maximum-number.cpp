#include <iostream>
#include <set>

using namespace std;

int n, m;
int queries;

int main() {
    cin >> n >> m;

    set<int> se;
    for(int i = 1; i <= m; i++){
        se.insert(i);
    }

    for (int i = 0; i < n; i++) {
        cin >> queries;
        se.erase(queries);

        cout << *se.rbegin() << endl;
    }

    // Please write your code here.

    return 0;
}
