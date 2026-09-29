#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <utility>

using namespace std;

int n, k;
int arr;

int main() {
    cin >> n >> k;

    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++) {
        cin >> arr;
        mp[arr]++;
    }
    // Please write your code here.

    vector<pair<int, int>> v(mp.begin(), mp.end());
    sort(v.begin(), v.end(),
        [](const auto& a, const auto& b){
            if(a.second != b.second) return a.second > b.second;

            return a.first > b.first;
        }
    );

    for(int i = 0; i < k; i++){
        cout << v[i].first << " ";
    }

    return 0;
}
