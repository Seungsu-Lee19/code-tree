#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

int n;
string words;

int main() {
    cin >> n;

    unordered_map<string, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> words;
        sort(words.begin(), words.end());
        mp[words]++;
    }

    // Please write your code here.
    int ans = 0;
    for(auto [str, cnt]: mp){
        ans = max(ans, cnt);
    }

    cout << ans;


    return 0;
}
