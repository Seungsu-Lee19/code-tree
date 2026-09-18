#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int n;
int grid[10][10];

int usedX[10] = {0, };
int usedY[10] = {0, };

int ans = 0;

void back(int cnt, int value, int start){
    if(cnt == n){
        ans = max(ans, value);
        return;
    }

    for(int i = 0; i < n; i++){
        if(usedY[i] == 0){
            // usedX[i] = 1;
            usedY[i] = 1;

            back(cnt + 1, value + grid[start][i], start + 1);

            // usedX[i] = 0;
            usedY[i] = 0;
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    back(0, 0, 0);
    cout << ans;

    return 0;
}
