#include <iostream>

using namespace std;

int n;
int x;
char dir;

int main() {
    cin >> n;

    int check[2001] = {0, };
    int idx = 1000;

    for (int i = 0; i < n; i++) {
        cin >> x >> dir;

        if(dir == 'L'){
            for(int j = 0; j < x; j++){
                check[--idx]++;
            }
        }
        else{
            for(int j = 0; j < x; j++){
                check[idx++]++;
            }
        }
    }

    // Please write your code here.

    int ans = 0;
    for(int i = 0; i < 2001; i++){
        if(check[i] >= 2) ans++;
    }

    cout << ans;

    return 0;
}