#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string str;

int main() {
    cin >> str;

    // Please write your code here.
    sort(str.begin(), str.end());
    cout << str;

    return 0;
}