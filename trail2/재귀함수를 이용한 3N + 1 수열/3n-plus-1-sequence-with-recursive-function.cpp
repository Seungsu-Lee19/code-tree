#include <iostream>

using namespace std;

int n;

int func(int n){
    if(n == 1) return 0;

    if(n % 2 == 0) n = n / 2;
    else n = (n * 3) + 1;

    return func(n) + 1;
}

int main() {
    cin >> n;

    // Please write your code here.
    cout << func(n);
    return 0;
}