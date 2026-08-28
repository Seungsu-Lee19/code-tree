#include <iostream>

using namespace std;

int n, m;
int A[100];

int func(){
    int ret = 0;

    while(m >= 1){
        ret = ret + A[m - 1];
        if(m % 2 == 0) m /= 2;
        else m -= 1;
    }

    return ret;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    // Please write your code here.
    cout << func();
    return 0;
}