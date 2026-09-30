#include <iostream>
#include <set>

using namespace std;

int n, m;
int a[100000];

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // m명의 사람을 어디에 앉아야, 앉은 사람 수를 최대로 할 수 있을까?
    // 순서대로 앉도록 하다가, 못 앉으면 종료.

    set<int> se;
    int ans = 0;
    for(int i = 1; i <= m; i++) se.insert(i);

    for(int i = 0; i < n; i++){
        auto it = se.upper_bound(a[i]);

        if(it == se.begin()) {
            // cout << i; 
            break;
        }
        
        it--;
        se.erase(it);
        ans++;
    }

    cout << ans;
    return 0;
}
