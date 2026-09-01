#include <iostream>

using namespace std;

int n;
int x1, y1;
int x2, y2;

int main() {
    cin >> n;

    int grid[201][201] = {};

    for (int i = 1; i <= n; i++) {
        cin >> x1 >> y1 >> x2 >> y2;

        x1 += 100;
        y1 += 100;
        x2 += 100;
        y2 += 100;

        int c;
        if(i % 2 == 1) c = 1;
        else c = 2;

        for(int p = x1; p < x2; p++){
            for(int q = y1; q < y2; q++){
                grid[p][q] = c;
            }
        }
    }

    // Please write your code here.

    int ans = 0;
    for(int i = 0; i < 201; i++){
        for(int j = 0; j < 201; j++){
            if(grid[i][j] == 2) ans++;
        }
    }
    cout << ans;

    return 0;
}