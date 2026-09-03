#include <iostream>

using namespace std;

int n, t;

int main() {
    cin >> n >> t;

    int s = 3 * n;
    int velt[s];
    for(int i = 0; i < s; i++){
        cin >> velt[i];
    }

    // Please write your code here.
    t %= s;
    for(int i = 0; i < s; i++){
        int r = (i - t + s) % s;

        cout << velt[r] << " ";

        if(i != 0 && i % n == n - 1) cout << endl;
    }


    return 0;
}
