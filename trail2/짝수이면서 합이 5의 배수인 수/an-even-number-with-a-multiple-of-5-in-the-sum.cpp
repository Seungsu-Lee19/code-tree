#include <iostream>

using namespace std;

int n;

string check(int n){
    if(n % 2 != 0) return "No";

    int s = ((n / 10) + (n % 10));

    if(s % 5 == 0 && s >= 5) return "Yes";
    else return "No";
}

int main() {
    cin >> n;

    // Please write your code here.
    cout << check(n);

    return 0;
}