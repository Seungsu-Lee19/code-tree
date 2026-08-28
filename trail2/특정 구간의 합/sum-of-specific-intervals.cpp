#include <iostream>

using namespace std;

int n, m;
int arr[101];
int queryA1[101];
int queryA2[101];

int func(int start, int end){
    int ret = 0;
    for(int i = start; i <= end; i++){
        ret += arr[i];
    }

    return ret;
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> queryA1[i] >> queryA2[i];
    }

    // Please write your code here.
    
    for (int i = 0; i < m; i++) {
        cout << func(queryA1[i], queryA2[i]) << endl;
    }


    return 0;
}