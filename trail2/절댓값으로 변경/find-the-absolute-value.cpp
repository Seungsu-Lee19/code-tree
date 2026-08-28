#include <iostream>

using namespace std;

int n;
int arr[50];

void tt(int a[]){
    for(int i = 0; i < n; i++){
        if(a[i] < 0) a[i] = -a[i];
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Please write your code here.
    tt(arr);
    
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}