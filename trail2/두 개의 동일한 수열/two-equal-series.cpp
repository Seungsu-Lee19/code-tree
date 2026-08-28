#include <iostream>
#include <algorithm>

using namespace std;

int n;
int A[100];
int B[100];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }

    // Please write your code here.
    sort(A, A + n);
    sort(B, B + n);

    bool isSame = true;
    for(int i = 0; i < n; i++){
        if(A[i] != B[i]){
            isSame = false;
            break;
        }
    }

    if(isSame) cout << "Yes";
    else cout << "No";

    return 0;
}