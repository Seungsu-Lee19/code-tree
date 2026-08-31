#include <iostream>

using namespace std;

int a, b, c, d;

int main() {
    cin >> a >> b >> c >> d;

    // Please write your code here.
    int time;

    time = (c - a) * 60 + (d - b);
    cout << time;


    return 0;
}