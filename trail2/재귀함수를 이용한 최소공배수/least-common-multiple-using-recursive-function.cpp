#include <iostream>

using namespace std;

int n;
int arr[10];

int func(int t, int r){
    if(t == n) return r;

    int m = 1;
    for(int i = 1; i <= min(arr[t], r); i++){
        if(r % i == 0 && arr[t] % i == 0){
            m = i;
        }
    }

    r = (arr[t] * r) / m;
    return func(t + 1, r);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Please write your code here.
    cout << func(0, arr[0]);
    return 0;
}