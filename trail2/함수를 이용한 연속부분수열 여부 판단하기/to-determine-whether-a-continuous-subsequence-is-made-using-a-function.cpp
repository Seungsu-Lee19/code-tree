#include <iostream>

using namespace std;

int n1, n2;
int a[100], b[100];

bool check(){
    for(int i = 0; i < n1; i++){
        bool isPos = true;
        for(int j = 0; j < n2; j++){
            if(a[i + j] != b[j]) {
                isPos = false;
                break;
            }
        }

        if(isPos) return true;
    }
    return false;
}

int main() {
    cin >> n1 >> n2;

    for (int i = 0; i < n1; i++) cin >> a[i];

    for (int i = 0; i < n2; i++) cin >> b[i];

    // Please write your code here.
    if(check()) cout << "Yes";
    else cout << "No";

    return 0;
}