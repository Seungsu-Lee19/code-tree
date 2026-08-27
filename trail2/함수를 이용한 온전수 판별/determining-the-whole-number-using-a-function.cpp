#include <iostream>

using namespace std;

int a, b;

int main() {
    cin >> a >> b;

    // Please write your code here.
    int cnt = 0;
    for(int i = a; i <= b; i++){
        if(i % 2 == 0) continue;
        else if(i % 10 == 5) continue;
        else if(i % 3 == 0 && i % 9 != 0) continue;

        cnt += 1;
    }

    cout << cnt;

    return 0;
}