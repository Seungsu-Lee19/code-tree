#include <iostream>

using namespace std;

int N;

void funcA(int n){
    if(n > N) return;

    cout << n << " ";
    funcA(n + 1);
}

void funcB(int n){
    if(n == 0) return;

    cout << n << " ";
    funcB(n - 1);
}

int main() {
    cin >> N;

    // Please write your code here.
    funcA(1);
    cout << "\n";
    funcB(N);

    return 0;
}