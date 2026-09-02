#include <iostream>
#include <string>

using namespace std;

string dirs;

int main() {
    cin >> dirs;

    // Please write your code here.
    int x = 0;
    int y = 0;
    int dir = 0;

    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {1, 0, -1, 0};

    for(int i = 0; i < dirs.length(); i++){
        char cmd = dirs[i];

        if(cmd == 'F'){
            x = x + dx[dir];
            y = y + dy[dir];
        }
        else if(cmd == 'L'){
            dir = (dir + 1) % 4;
        }
        else if(cmd == 'R'){
            dir = ((dir - 1) + 4) % 4;
        }
    }

    cout << x << " " << y;

    return 0;
}