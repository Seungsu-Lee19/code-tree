#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int n, m;
string words;
string queries;

int main() {
    cin >> n >> m;

    unordered_map<string, int> mp1;
    unordered_map<int, string> mp2;

    for (int i = 1; i <= n; i++) {
        cin >> words;
        mp1[words] = i;
        mp2[i] = words;
    }

    for (int i = 0; i < m; i++) {
        cin >> queries;

        if(mp1.find(queries) != mp1.end()){
            cout << mp1[queries] << endl;
        }
        else{
            cout << mp2[stoi(queries)] << endl;
        }
    }

    // Please write your code here.

    return 0;
}
