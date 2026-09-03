#include <iostream>

using namespace std;

int n, m;
int grid[100][100];

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    int ans = 0;
    for(int i = 0; i < n; i++){
        int prev = grid[i][0];
        int cnt = 0;
        
        for(int j = 0; j < n; j++){
            if(grid[i][j] == prev){
                cnt++;
            }
            else{
                prev = grid[i][j];
                cnt = 1;
            }

            if(cnt >= m) {
                ans++;
                break;
            }
        }
    }
    
    for(int i = 0; i < n; i++){
        int prev = grid[0][i];
        int cnt = 0;
        
        for(int j = 0; j < n; j++){
            if(grid[j][i] == prev){
                cnt++;
            }
            else{
                prev = grid[j][i];
                cnt = 1;
            }

            if(cnt >= m) {
                ans++;
                break;
            }
        }
    }

    cout << ans;

    return 0;
}
