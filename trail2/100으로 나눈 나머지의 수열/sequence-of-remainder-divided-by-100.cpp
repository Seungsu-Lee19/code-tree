#include <iostream>

using namespace std;

int N;

int func(int n){
    if(n == 1) return 2;
    else if(n == 2) return 4;

    return (func(n - 1) * func(n - 2)) % 100;
}

int main() {
    cin >> N;

    // Please write your code here.
    cout << func(N);
    return 0;
}