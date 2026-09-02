#include <iostream>

using namespace std;

int N;
int arr[1000];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // Please write your code here.
    int cnt = 1;
    int cnt_max = 1;

    for(int i = 0; i < N - 1; i++){
        if(arr[i] < 0 && arr[i + 1] < 0){
            cnt++;
        }
        else if(arr[i] > 0 && arr[i + 1] > 0) cnt++;
        else{
            cnt = 1;
        }
        
        if(cnt > cnt_max) cnt_max = cnt;
    }

    cout << cnt_max;

    return 0;
}