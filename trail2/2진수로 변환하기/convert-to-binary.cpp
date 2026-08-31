#include <iostream>

using namespace std;

int n;

int main() {
    cin >> n;

    // Please write your code here.
    int digit[100] = {0, };
    int cnt = 0;
    while(1){
        if(n < 2){
            digit[cnt] = n;
            break;
        }

        digit[cnt++] = n % 2;
        n /= 2;
    }

    for(int i = cnt; i >= 0; i--){
        cout << digit[i];
    }

    return 0;
}