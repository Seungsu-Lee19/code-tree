#include <iostream>

using namespace std;

int n, m, k;
int grid[100][100];

int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    // k ~ (k + m - 1)
    k--;

    int w_x = n - 1;
    for(int x = 0; x < n - 1; x++){
        for(int y = k; y < k + m; y++){
            if(grid[x + 1][y]){
                w_x = x;
                break;
            }
        }

        if(w_x != n - 1){
            break;
        }
    }
    for(int y = k; y < k + m; y++){
        grid[w_x][y] = 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
