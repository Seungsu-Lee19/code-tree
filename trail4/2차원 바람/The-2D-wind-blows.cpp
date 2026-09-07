#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, q;
vector<vector<int>> a;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void rotate_v(int r1, int c1, int r2, int c2){
    int temp = a[r1][c2];
    for(int y = c2; y >= c1 + 1; y--){
        a[r1][y] = a[r1][y - 1];
    }
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         cout << a[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";


    int temp2 = a[r2][c2];
    for(int x = r2; x >= r1 + 1; x--){
        a[x][c2] = a[x - 1][c2];
    }
    a[r1 + 1][c2] = temp;
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         cout << a[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";


    temp = a[r2][c1];
    for(int y = c1; y <= c2 - 1; y++){
        a[r2][y] = a[r2][y + 1]; 
    }
    a[r2][c2 - 1] = temp2;
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         cout << a[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";


    for(int x = r1; x <= r2 - 1; x++){
        a[x][c1] = a[x + 1][c1];
    }
    a[r2 - 1][c1] = temp;

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         cout << a[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";
}

int main() {
    cin >> n >> m >> q;
    for (int i = 0; i < n; i++){
        vector<int> row;
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            row.push_back(x);
        }
        a.push_back(row);
    }

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         cout << a[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";

    for (int i = 0; i < q; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;

        r1--;
        c1--;
        r2--;
        c2--;

        rotate_v(r1, c1, r2, c2);
        vector<vector<int>> temp = a;

        for(int i = r1; i <= r2; i++){
            for(int j = c1; j <= c2; j++){
                int cnt = 1;
                int s = a[i][j];

                for(int k = 0; k < 4; k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

                    cnt++;
                    s += a[nx][ny];
                }

                temp[i][j] = s / cnt;
            }
        }

        a = temp;
    }

    // Please write your code here.



    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
