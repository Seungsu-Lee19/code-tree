#include <iostream>

using namespace std;

int N;

int func(int n, int s){
    if(n <= 0) return s;

    return func(n / 10, s + (n % 10) * (n % 10));
}

int main() {
    cin >> N;

    // Please write your code here.
    cout << func(N, 0);
    return 0;
}