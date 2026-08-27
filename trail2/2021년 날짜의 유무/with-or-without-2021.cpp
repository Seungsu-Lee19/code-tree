#include <iostream>

using namespace std;

int M, D;

int main() {
    cin >> M >> D;

    // Please write your code here.
    // 1 - 31, 2 - 28, 3 - 31, 4 - 30, 5 - 31, 6 - 30, 7 - 31, 8 - 31, 9 -30, 10 - 31, 11 - 30, 12 - 31
    if(M > 12 || D > 31) cout << "No";
    
    else if(M == 2){
        if(D <= 28) cout << "Yes";
        else cout << "No";
    }
    else if(M < 8 && M % 2 == 0){
        if(D <= 30) cout << "Yes";
        else cout << "No";
    }
    else if(M < 8 && M % 2 != 0){
        if(D <= 31) cout << "Yes";
        else cout << "No";
    }
    else if(M >= 8 && M % 2 == 0){
        if(D <= 31) cout << "Yes";
        else cout << "No";
    }
    else if(M >= 8 && M % 2 != 0){
        if(D <= 30) cout << "Yes";
        else cout << "No";
    }
    else cout << "No";


    return 0;
}