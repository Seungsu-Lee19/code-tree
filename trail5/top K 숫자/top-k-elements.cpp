#include <iostream>
#include <set>

using namespace std;

int n, k;
long long arr;

int main() {
    cin >> n >> k;

    set<long long> se;
    for (int i = 0; i < n; i++) {
        cin >> arr;
        se.insert(arr);
    }

    // Please write your code here.
    int cnt = 0;
    for(auto it = se.rbegin(); it != se.rend(); ++it){
        if(cnt < k) cout << *it << " ";
        else break;

        cnt++;
    }

    return 0;
}
