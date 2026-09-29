#include <iostream>
#include <string>
#include <map>
#include <iomanip>

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

    // Please write your code here.

    cout << fixed << setprecision(4);
    for(auto [str, cnt]: mp){
        cout << str << " " << ((double)cnt / n) * 100 << endl;
    }

    return 0;
}
