#include <iostream>
#include <algorithm>

using namespace std;

int n, m;

int main() {
    cin >> n >> m;

    // Please write your code here.
    int mx = max(n, m);
    while(1){
        if(mx % n == 0 && mx % m == 0){
            cout << mx;
            break;
        }
        mx += 1;
    }
    return 0;
}