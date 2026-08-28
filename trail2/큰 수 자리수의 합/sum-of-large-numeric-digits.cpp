#include <iostream>

using namespace std;

int a, b, c;

int func(int n){
    if(n == 0) return 0;

    return func(n / 10) + (n % 10);
}

int main() {
    cin >> a >> b >> c;

    // Please write your code here.

    cout << func(a * b * c);

    return 0;
}