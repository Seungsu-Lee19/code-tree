#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, q;

int main() {
    cin >> n >> m >> q;

    vector<vector<int>> a;
    for (int i = 0; i < n; i++) {
        vector<int> temp;
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            temp.push_back(x);
        }
        a.push_back(temp);
    }

    for (int i = 0; i < q; i++) {
        int r;
        char d;
        cin >> r >> d;
        r--;

        if(d == 'R'){
            rotate(a[r].begin(), a[r].begin() + 1, a[r].end());
            d = 'L';
        }
        else{
            rotate(a[r].begin(), a[r].end() - 1, a[r].end());
            d = 'R';
        }

        char temp = d;
        for(int i = r; i >= 1; i--){
            int isRotate = false;
            for(int j = 0; j < m; j++){
                if(a[i][j] == a[i - 1][j]){
                    isRotate = true;
                    if(temp == 'R'){
                        rotate(a[i - 1].begin(), a[i - 1].begin() + 1, a[i - 1].end());
                        temp = 'L';
                    }
                    else{
                        rotate(a[i - 1].begin(), a[i - 1].end() - 1, a[i - 1].end());
                        temp = 'R';
                    }
                    break;
                }
            }

            if(isRotate == false) break;
        }

        temp = d;
        for(int i = r; i < n - 1; i++){
            int isRotate = false;
            for(int j = 0; j < m; j++){
                if(a[i][j] == a[i + 1][j]){
                    isRotate = true;
                    if(temp == 'R'){
                        rotate(a[i + 1].begin(), a[i + 1].begin() + 1, a[i + 1].end());
                        temp = 'L';
                    }
                    else{
                        rotate(a[i + 1].begin(), a[i + 1].end() - 1, a[i + 1].end());
                        temp = 'R';
                    }
                    break;
                }
            }

            if(isRotate == false) break;
        }
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
