#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int n;
int grid[10][10];
int ans = 0;
int usedY[10];

void back(int row, int value){
    if(row == n){
        ans = max(ans, value); 
        return;       
    }

    for(int j = 0; j < n; j++){
        if(usedY[j] == 0){
            usedY[j] = 1;

            back(row + 1, min(value, grid[row][j]));

            usedY[j] = 0;
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
    back(0, INT_MAX);
    cout << ans;

    return 0;
}
