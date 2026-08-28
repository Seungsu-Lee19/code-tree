#include <iostream>

using namespace std;

int N;

int func(int n, int s){
    if(n == 1) return s;

    if(n % 2 == 0) return func(n / 2, s + 1);
    else return func(n / 3, s + 1);
}

int main() {
    cin >> N;

    // Please write your code here.
    cout << func(N, 0);

    return 0;
}