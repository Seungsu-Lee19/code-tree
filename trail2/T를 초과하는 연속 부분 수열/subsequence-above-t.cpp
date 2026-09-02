#include <iostream>
#include <algorithm>

using namespace std;

int n, t;
int arr[1000];

int main() {
    cin >> n >> t;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Please write your code here.
    int cnt = 0;
    int cnt_max = 0;

    for(int i = 0; i < n; i++){
        if(arr[i] > t) cnt++;
        else cnt = 0;

        cnt_max = max(cnt, cnt_max);
    }

    cout << cnt_max;

    return 0;
}