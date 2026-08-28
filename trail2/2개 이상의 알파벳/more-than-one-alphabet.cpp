#include <iostream>
#include <string>

using namespace std;

string A;

string check(){
    int len = A.length();
    bool isTrue = false;
    for(int i = 1; i < len; i++){
        if(A[0] != A[i]) isTrue = true;
    }

    if(isTrue) return "Yes";
    else return "No";
}

int main() {
    cin >> A;

    // Please write your code here.
    cout << check();
    return 0;
}