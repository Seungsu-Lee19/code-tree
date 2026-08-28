#include <iostream>
#include <string>

using namespace std;

string text;
string pattern;

int f(int n){
    int l = pattern.length();
    for(int i = 0; i < l; i++){
        if(text[n + i] != pattern[i]) return 0;
    }
    return 1;
}

int main() {
    cin >> text;
    cin >> pattern;

    // Please write your code here.
    int l = text.length() - pattern.length();
    int r = -1;
    for(int i = 0; i <= l; i++){
        if(f(i)){
            r = i;
            break;
        }
    }

    cout << r;

    return 0;
}