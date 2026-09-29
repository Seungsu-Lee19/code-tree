#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int n;
string words;

int main() {
    cin >> n;

    unordered_map<string, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> words;
        mp[words]++;
    }

    int ans = 0;
    for(auto [str, cnt]: mp){
        ans = max(ans, cnt);
    }
    cout << ans;

    return 0;
}
