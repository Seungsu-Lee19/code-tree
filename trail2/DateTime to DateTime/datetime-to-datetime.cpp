#include <iostream>

using namespace std;

int a, b, c;

int main() {
    cin >> a >> b >> c;

    // Please write your code here.
    int date = a - 11;
    int time = -(11 * 60) - 11;
    time = time + (b * 60) + c;

    int total = date * 24 * 60 + time;

    if(total < 0) cout << -1;
    else cout << total;

    return 0;
}