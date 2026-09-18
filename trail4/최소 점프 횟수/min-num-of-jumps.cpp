#include <iostream>
#include <algorithm>

using namespace std;

int n;
int ans = 20;
int num[10];

void back(int cur, int cnt){
    if(cur == n - 1){
        ans = min(ans, cnt);
    }
    else if(cur > n - 1) return;

    for(int i = 1; i <= num[cur]; i++){
        // if(cur + i > n) continue;

        back(cur + i, cnt + 1);
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    // Please write your code here.
    back(0, 0);
    if(ans == 20) cout << -1;
    else cout << ans;
    
    return 0;
}
