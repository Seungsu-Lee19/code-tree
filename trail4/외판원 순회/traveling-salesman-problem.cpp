#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int n;
int A[10][10];
int used[10] = {0, };
int ans = INT_MAX;

void back(int cnt, int cur, int value){
    if(cnt == n){
        ans = min(ans, value);
        return;
    }

    for(int i = 0; i < n; i++){
        if(cur == i) continue;
        if(cnt != n - 1 && i == 0) continue;
        if(A[cur][i] == 0) continue;

        if(used[i] == 0){
            used[i] = 1;

            back(cnt + 1, i, value + A[cur][i]);

            used[i] = 0;
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    // Please write your code here.
    back(0, 0, 0);
    cout << ans;

    return 0;
}
