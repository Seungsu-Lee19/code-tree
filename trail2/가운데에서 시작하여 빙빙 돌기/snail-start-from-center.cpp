#include <iostream>

using namespace std;

int n;
int grid[100][100];

int main() {
    cin >> n;

    // Please write your code here.
    int dir = 0;
    int x = n / 2;
    int y = n / 2;

    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {1, 0, -1, 0};

    int s = 1;
    int cnt = 1;
    for(int i = 1; i <= n * n; i++){
        grid[x][y] = i;

        x = x + dx[dir];
        y = y + dy[dir];
        if(i == 1) {
            dir = (dir + 1) % 4;
        }
        else if(x == y && x < n / 2){
            dir = (dir + 1) % 4;
        }
        else if(x + 1== y && x >= n / 2 && y > n / 2){
            dir = (dir + 1) % 4;
        }
        else if(x + y == n - 1){
            dir = (dir + 1) % 4;
        }

        // cout << x << " " << y << " " << i << " " << dir << endl;
        
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
 
    return 0;
}
