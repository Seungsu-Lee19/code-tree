#include <iostream>

using namespace std;

int N;

int func(int n, int s){
    if(n == 0) return s;

    return func(n - 1, s * n);
}

int main() {
    cin >> N;

    // Please write your code here.
    cout << func(N, 1);
    return 0;
}