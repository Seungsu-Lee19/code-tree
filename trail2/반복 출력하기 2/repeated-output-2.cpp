#include <iostream>

using namespace std;

int N;

void hello(int n){
    if(n == 0) return;

    cout << "HelloWorld\n";
    hello(n - 1);
}

int main() {
    cin >> N;

    // Please write your code here.
    hello(N);

    return 0;
}