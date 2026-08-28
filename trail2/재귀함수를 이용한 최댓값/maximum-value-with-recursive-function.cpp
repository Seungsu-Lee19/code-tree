#include <iostream>

using namespace std;

int n;
int arr[100];

int func(int idx, int s){
    if(idx == n) return s;

    return func(idx + 1, max(arr[idx], s));
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Please write your code here.
    cout << func(1, arr[0]);
    return 0;
}