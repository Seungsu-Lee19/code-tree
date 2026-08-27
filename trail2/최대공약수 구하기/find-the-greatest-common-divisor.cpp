#include <iostream>

using namespace std;

int n, m;

int main() {
    cin >> n >> m;

    // Please write your code here.
    int max = 1;
    int min;
    if(n < m) min = n;
    else min = m;

    for(int i = 2; i <= min; i++){
        if(n % i == 0 && m % i == 0) max = i;
    }
    cout << max;

    return 0;
}