#include <iostream>
#include <tuple>

#define MAXID 200001

using namespace std;

int n;
int x;
char dir;

int main() {
    cin >> n;

    tuple<int, int, int> tile[MAXID] = {};
    int cur = 100000;

    for (int i = 0; i < n; i++) {
        cin >> x >> dir;
        int w, b, c;
        
        if(dir == 'L'){
            for(int j = 0; j < x; j++){
                tie(w, b, c) = tile[cur];
                // cout << w << " " << b << " " << c << endl;
                tile[cur--] = make_tuple(w + 1, b, -1);
            }
            cur++;
        }
        else{
            for(int j = 0; j < x; j++){
                tie(w, b, c) = tile[cur];
                // cout << w << " " << b << " " << c << endl;
                tile[cur++] = make_tuple(w, b + 1, 1);
            }
            cur--;
        }
    }

    // Please write your code here.
    int w = 0;
    int b = 0;
    int g = 0;

    for(int i = 0; i < MAXID; i++){
        int _w, _b, c;
        tie(_w, _b, c) = tile[i];

        // if(_w >= 1 || _b >= 1) cout << i << " : " << _w << " " << _b << " " << c << endl;

        if(_w >= 2 && _b >= 2) g++;
        else if(c == -1) w++;
        else if(c == 1) b++;
        
    }

    cout << w << " " << b << " " << g;

    return 0;
}