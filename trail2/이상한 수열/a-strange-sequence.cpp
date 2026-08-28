#include <iostream>

using namespace std;

int N;

int func(int n){
    if(n == 1) return 1;
    else if(n == 2) return 2;

    return func(n / 3) + func(n - 1);
}

int main() {
    cin >> N;

    // Please write your code here.
    cout << func(N);
    return 0;
}