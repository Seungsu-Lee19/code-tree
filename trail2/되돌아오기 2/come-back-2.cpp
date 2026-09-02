#include <iostream>
#include <string>

using namespace std;

string commands;

int main() {
    cin >> commands;

    // Please write your code here.
    int x = 0;
    int y = 0;
    int dir = 0;

    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {-1, 0, 1, 0};

    int ans = -1;

    for(int i = 0; i < commands.length(); i++){
        char cmd = commands[i];
        
        if(cmd == 'F'){
            x += dx[dir];
            y += dy[dir];

            if(x == 0 && y == 0){
                ans = i + 1;
                break;
            }
        }
        else if(cmd == 'L'){
            dir = (dir + 1) % 4;
        }
        else if(cmd == 'R'){
            dir = ((dir - 1) + 4) % 4;
        }
    }

    cout << ans;
    
    return 0;
}