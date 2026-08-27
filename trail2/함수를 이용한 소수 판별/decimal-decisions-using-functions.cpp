#include <iostream>

using namespace std;

int a, b;

bool checkPrime(int n){
    int cnt = 1;
    for(int i = 2; i <=n; i++){
        if(n % i == 0) cnt += 1;

        if(cnt > 2) break;
    }

    return cnt == 2;
}

int main() {
    cin >> a >> b;

    // Please write your code here.
    int cnt = 0;
    for(int i = a; i <= b; i++){
        if(checkPrime(i)) cnt += i;
    }

    cout << cnt;

    return 0;
}