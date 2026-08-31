#include <iostream>
#include <string>

using namespace std;

string binary;

int main() {
    cin >> binary;

    // Please write your code here.
    int ans = 0;
    for(int i = 0; i < binary.length(); i++){
        ans = ans * 2 + int(binary[i] - '0');
    }

    cout << ans;

    return 0;
}