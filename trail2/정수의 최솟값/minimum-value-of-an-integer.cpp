#include <iostream>
#include <algorithm>

using namespace std;

int a, b, c;

int main() {
    cin >> a >> b >> c;

    // Please write your code here.
    cout << min(min(a, b), c);

    return 0;
}