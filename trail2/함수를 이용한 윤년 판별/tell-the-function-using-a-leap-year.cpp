#include <iostream>

using namespace std;

int y;

string checkYear(){
    if(y % 4 != 0) return "false";

    if(y % 100 == 0 && y % 400 != 0) return "false";

    return "true";
}

int main() {
    cin >> y;

    // Please write your code here.
    cout << checkYear();

    return 0;
}