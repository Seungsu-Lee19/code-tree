#include <iostream>
#include <algorithm>

using namespace std;

int n;
int A[100];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    // Please write your code here.
    int ans = 1000000;
    for(int i = 0; i < n; i++){
        int s = 0;
        for(int p = 0; p < i; p++){
            s = s + (A[p] * (i - p));
        }
        for(int q = i + 1; q < n; q++){
            s = s + (A[q] * (q - i));
        }

        ans = min(ans, s);
    }

    cout << ans;

    return 0;
}