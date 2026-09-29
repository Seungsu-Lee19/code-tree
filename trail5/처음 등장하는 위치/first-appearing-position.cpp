#include <iostream>
#include <map>

using namespace std;

int n;
long long arr;

int main() {
    cin >> n;

    map<long long, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> arr;
        if(mp.find(arr) == mp.end()) mp[arr] = i + 1;
    }

    // Please write your code here.
    for(auto [ar, idx]: mp){
        cout << ar << " " << idx << endl;
    }

    return 0;
}
