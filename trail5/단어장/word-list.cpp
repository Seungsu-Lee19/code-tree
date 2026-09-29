#include <iostream>
#include <string>
#include <map>

using namespace std;

int n;
string words;

int main() {
    cin >> n;

    map<string, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> words;
        mp[words]++;
    }

    for(auto [str, cnt]: mp){
        cout << str << " " << cnt << endl;
    }

    return 0;
}
