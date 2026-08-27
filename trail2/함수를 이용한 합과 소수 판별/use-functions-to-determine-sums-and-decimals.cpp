#include <iostream>

using namespace std;

int a, b;

bool check(int n){
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(n % i == 0) cnt += 1;

        if(cnt > 2) return 0;
    }

    return ((n / 10) + (n % 10)) % 2 == 0;
}

int main() {
    cin >> a >> b;

    // Please write your code here.
    int cnt = 0;
    for(int i = a; i <= b; i++){
        if(check(i)) cnt += 1;
    }
    cout << cnt;

    return 0;
}