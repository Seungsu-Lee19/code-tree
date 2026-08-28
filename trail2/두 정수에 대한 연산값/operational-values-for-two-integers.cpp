#include <iostream>

using namespace std;

int a, b;

void tt(int &n, int &m){
    if(n > m){
        n += 25;
        m *= 2;
    }
    else{
        m += 25;
        n *= 2;
    }
}

int main() {
    cin >> a >> b;

    // Please write your code here.
    tt(a, b);
    cout << a << " " << b;
    return 0;
}