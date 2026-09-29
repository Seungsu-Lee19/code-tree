#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int n;
long long x, y;

int main() {
    cin >> n;

    unordered_map<long long, long long> mp;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        if(mp.find(x) != mp.end()){
            mp[x] = min(mp[x], y);
        }
        else mp[x] = y;
    }

    // Please write your code here.
    long long ans = 0;
    for(auto [i, j]: mp){
        ans += j;
    }

    cout << ans;

    return 0;
}