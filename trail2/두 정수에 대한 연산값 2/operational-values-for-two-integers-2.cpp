#include <iostream>

using namespace std;

int a, b;

void tt(int &n, int &m){
    if(n > m){
        m += 10;
        n *= 2;
    }
    else{
        n += 10;
        m *= 2;
    }
}

int main() {
    cin >> a >> b;

    // Please write your code here.
    tt(a, b);
    cout << a << " " << b;
    return 0;
}