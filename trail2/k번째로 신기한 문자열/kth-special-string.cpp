#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n, k;
string t;
string str[100];

int main() {
    cin >> n >> k >> t;

    for (int i = 0; i < n; i++) {
        cin >> str[i];
    }

    // Please write your code here.
    sort(str, str + n);
    for(int i = 0; i < n; i++){
        if(str[i].compare(0, t.length(), t) == 0){
            k -= 1;
        }

        if(k == 0) {
            cout << str[i];
            break;
        }
    }

    return 0;
}