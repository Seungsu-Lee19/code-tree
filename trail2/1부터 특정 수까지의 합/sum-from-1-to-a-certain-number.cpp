#include <iostream>

using namespace std;

int N;

int sum(int n){
    int r = 0;
    for(int i = 1; i <= n; i++){
        r += i;
    }
    return r;
}

int main() {
    cin >> N;

    // Please write your code here.
    cout << sum(N) / 10;

    return 0;
}