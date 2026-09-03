#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, t;

int main() {
    cin >> n >> t;

    int u[2 * n];

    for (int i = 0; i < n; i++) cin >> u[i];

    for (int i = n; i < 2 * n; i++) cin >> u[i];


    // Please write your code here.
    t %= (2 * n);
    for(int i = 0; i < 2 * n; i++){
        int r = (i - t + (2*n)) % (2 * n);
        cout << u[r] << " ";

        if(i == n - 1) cout << endl;
    }

    return 0;
}
