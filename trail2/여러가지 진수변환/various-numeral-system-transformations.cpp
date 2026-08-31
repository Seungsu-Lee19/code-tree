#include <iostream>

using namespace std;

int N, B;

int main() {
    cin >> N >> B;

    // Please write your code here.
    int digit[100] = {0, };
    int cnt = 0;
    while(1){
        if(N < B){
            digit[cnt] = N;
            break;
        }

        digit[cnt++] = N % B;
        N /= B;
    }

    for(int i = cnt; i >= 0; i--){
        cout << digit[i];
    }

    return 0;
}