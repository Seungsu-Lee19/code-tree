#include <iostream>

using namespace std;

int N;
char dir;
int dist;

int main() {
    cin >> N;

    int x = 0;
    int y = 0;
    int t = 0;
    int ans = -1;
    for (int i = 0; i < N; i++) {
        cin >> dir >> dist;

        if(ans != -1) continue;

        for(int k = 0; k < dist; k++){
            t++;
            if(dir == 'W'){
                y--;
            }
            else if(dir == 'E'){
                y++;
            }
            else if(dir == 'N'){
                x++;
            }
            else if(dir == 'S'){
                x--;
            }

            if(x == 0 && y == 0) {
                ans = t;
                break;
            }
        }
    }

    // Please write your code here.
    cout << ans;

    return 0;
}