#include <iostream>

using namespace std;

int a, b;

int multi(){
    int r = a;
    for(int i = 1; i < b; i++){
        r = r * a;
    }
    return r;
}

int main() {
    cin >> a >> b;

    // Please write your code here.
    cout << multi();
    return 0;
}