#include <iostream>
#include <string>

using namespace std;

string N;

int main() {
    cin >> N;

    // Please write your code here.
    int n = 0;
    for(int i = 0; i < N.length(); i++){
        n = n * 2 + (N[i] - '0');
    }
    n *= 17;

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