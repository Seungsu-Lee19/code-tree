#include <iostream>
#include <string>

using namespace std;

int a, b;
string n;

int main() {
    cin >> a >> b;
    cin >> n;

    // Please write your code here.
    int dec = 0;
    for(int i = 0; i < n.length(); i++){
        dec = dec * a + (n[i] - '0');
    }

    int cnt = 0;
    int digit[100] = {0, };
    while(1){
        if(dec < b){
            digit[cnt] = dec;
            break;
        }

        digit[cnt++] = dec % b;
        dec /= b;
    }

    for(int i = cnt; i >= 0; i--){
        cout << digit[i];
    }

    return 0;
}