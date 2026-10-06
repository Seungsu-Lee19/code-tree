#include <iostream>
#include <unordered_map>
#include <set>
#include <climits>

using namespace std;

const int MAX_N = 100000;
int n, q;

int main() {
    cin >> n >> q;

    set<int> se;
    int point;
    for (int i = 0; i < n; i++) {
        cin >> point;
        se.insert(point);
    }

    unordered_map<int, int> mp;
    int prev = INT_MIN;
    for(auto p: se){
        if(prev == INT_MIN) mp[p] = 1;
        else mp[p] = mp[prev] + 1;

        prev = p;
    }

    int a, b;
    for (int i = 0; i < q; i++) {
        cin >> a >> b;

        cout << mp[b] - mp[a] + 1 << "\n";
    }

    // Please write your code here.

    return 0;
}
