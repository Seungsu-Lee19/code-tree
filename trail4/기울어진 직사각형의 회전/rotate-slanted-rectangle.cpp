#include <iostream>

using namespace std;

int n;
int grid[100][100];
int r, c, m1, m2, m3, m4, dir;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> grid[i][j];

    cin >> r >> c >> m1 >> m2 >> m3 >> m4 >> dir;

    // Please write your code here.
    r--;
    c--;

    int temp = grid[r][c];
    int x = r;
    int y = c;

    if(dir == 0){
        for(int i = 0; i < m2; i++){
            grid[r - i][c - i] = grid[r - i - 1][c - i - 1];
        }
        x = x - m2;
        y = y - m2;
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < n; j++){
        //         cout << grid[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        // cout << "\n";
        

        for(int i = 0; i < m1; i++){
            grid[x - i][y + i] = grid[x - i - 1][y + i + 1];
        }
        x = x - m1;
        y = y + m1;
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < n; j++){
        //         cout << grid[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        // cout << "\n";

        for(int i = 0; i < m2; i++){
            grid[x + i][y + i] = grid[x + i + 1][y + i + 1];
        }
        x = x + m2;
        y = y + m2;
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < n; j++){
        //         cout << grid[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        // cout << "\n";

        for(int i = 0; i < m1; i++){
            grid[x + i][y - i] = grid[x + i + 1][y - i - 1];
        }

        grid[r - 1][c + 1] = temp;
    }
    else{
        for(int i = 0; i < m1; i++){
            grid[x - i][y + i] = grid[x - i - 1][y + i + 1];
        }
        x = x - m1;
        y = y + m1;
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < n; j++){
        //         cout << grid[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        // cout << "\n";

        for(int i = 0; i < m2; i++){
            grid[x - i][y - i] = grid[x - i - 1][y - i - 1];
        }
        x = x - m2;
        y = y - m2;
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < n; j++){
        //         cout << grid[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        // cout << "\n";

        for(int i = 0; i < m3; i++){
            grid[x + i][y - i] = grid[x + i + 1][y - i - 1];
        }
        x = x + m3;
        y = y - m3;
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < n; j++){
        //         cout << grid[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        // cout << "\n";

        for(int i = 0; i < m4; i++){
            grid[x + i][y + i] = grid[x + i + 1][y + i + 1];
        }

        grid[r - 1][c - 1] = temp;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
