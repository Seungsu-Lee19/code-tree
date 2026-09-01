#include <iostream>

using namespace std;

int N;
int x, y;

int main() {
    cin >> N;

    int grid[201][201] = {};
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        x += 100;
        y += 100;

        for(int i = x; i < x + 8; i++){
            for(int j = y; j < y + 8; j++){
                grid[i][j] = 1;
            }
        }
    }

    // Please write your code here.
    int ans = 0;
    for(int i = 0; i < 201; i++){
        for(int j = 0; j < 201; j++){
            ans += grid[i][j];
        }
    }
    cout << ans;

    return 0;
}