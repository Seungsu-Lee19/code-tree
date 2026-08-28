#include <iostream>
#include <string>

using namespace std;

string A;

string palin(){
    int l = A.length();
    for(int i = 0; i < l; i++){
        if(A[i] != A[l - i - 1]) return "No";
    }

    return "Yes";
}

int main() {
    cin >> A;

    // Please write your code here.
    cout << palin();

    return 0;
}