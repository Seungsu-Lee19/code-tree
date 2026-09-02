#include <iostream>

using namespace std;

int n;
char dir;
int dist;

int main() {
    cin >> n;

    int x = 0;
    int y = 0;
    for (int i = 0; i < n; i++) {
        cin >> dir >> dist;
        if(dir == 'W') x -= dist;
        else if(dir == 'S') y -= dist;
        else if(dir == 'E') x += dist;
        else if(dir == 'N') y += dist;
    }

    cout << x << " " << y;
    // Please write your code here.

    return 0;
}