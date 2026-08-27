#include <iostream>

using namespace std;

int Y, M, D;

int main() {
    cin >> Y >> M >> D;

    // Please write your code here.
    bool isYoon = true;

    if(Y % 4 != 0) isYoon = false;
    else if(Y % 4 == 0 && Y % 100 == 0) isYoon = false;

    if(Y % 4 == 0 && Y % 100 == 0 && Y % 400 == 0) isYoon = true;

    if(M == 2){
        if(isYoon && D <= 29) cout << "Winter";
        else if(isYoon == false && D <= 28) cout << "Winter";
        else cout << -1;
    }
    else if(M < 8 && M % 2 != 0){
        if(M < 3) cout << "Winter";
        else if(M < 6) cout << "Spring";
        else cout << "Summer";
    }
    else if(M < 8 && M % 2 == 0 && D < 31){
        if(M < 3) cout << "Winter";
        else if(M < 6) cout << "Spring";
        else cout << "Summer";
    }
    else if(M >= 8 && M % 2 == 0) {
        if(M >= 12) cout << "Winter";
        else if(M >= 9) cout << "Fall";
        else cout << "Summer";
    }
    else if(M >= 8 && M % 2 != 0 && D < 31){
        if(M >= 12) cout << "Winter";
        else if(M >= 9) cout << "Fall";
        else cout << "Summer";
    }
    else cout << -1;

    return 0;
}