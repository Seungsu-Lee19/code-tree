#include <iostream>

using namespace std;

int n, t;
int r, c;
char d;

int main() {
    cin >> n >> t;
    cin >> r >> c >> d;

    // Please write your code here.

    // U D L R
    for(int i = 0; i < t; i++){
        if(d == 'U'){
            r--;
            if(r < 1) {
                d = 'D';
                r++;
            }
        }
        else if(d == 'D'){
            r++;
            if(r > n) {
                d = 'U';
                r--;
            }
        }
        else if(d == 'L'){
            c--;
            if(c < 1) {
                d = 'R';
                c++;
            }
        }
        else if(d == 'R'){
            c++;
            if(c > n) {
                d = 'L';
                c--;
            }
        }

        // cout << r << " " << c << " " << d << endl;
    }

    cout << r << " " << c;

    return 0;
}