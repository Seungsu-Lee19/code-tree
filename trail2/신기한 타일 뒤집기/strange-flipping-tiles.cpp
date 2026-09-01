#include <iostream>

#define MAXID 100000

using namespace std;

int n;
int x;
char dir;

int main() {
    cin >> n;

    int tile[MAXID * 2 + 1] = {0,};
    int cur = MAXID;

    for (int i = 0; i < n; i++) {
        cin >> x >> dir;

        if(dir == 'L'){
            for(int j = 0; j < x; j++){
                tile[cur--] = -1;
            }
            cur++;
        }
        else{
            for(int j = 0; j < x; j++){
                tile[cur++] = 1;
            }
            cur--;
        }
    }

    // Please write your code here.

    int w = 0;
    int b = 0;
    for(int i = 0; i < MAXID * 2 + 1; i++){
        if(tile[i] == -1) w++;
        else if(tile[i] == 1) b++;
    }

    cout << w << " " << b;

    return 0;
}