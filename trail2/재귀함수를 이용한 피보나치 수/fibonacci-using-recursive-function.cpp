#include <iostream>

using namespace std;

int N;

int func(int n, int a, int b){
    if(n == N) return a + b;

    return func(n + 1, b, a + b);
}

int main() {
    cin >> N;

    // Please write your code here.
    if(N <= 2) cout << 1;
    else cout << func(3, 1, 1);
    return 0;
}