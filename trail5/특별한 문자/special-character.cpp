#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>

using namespace std;

string str;

int main() {
    cin >> str;

    // Please write your code here.
    unordered_map<char, pair<int, int>> mp;
    for(int i = 0; i < str.size(); i++){
        if(mp.find(str[i]) != mp.end()){
            mp[str[i]].first++;
        }
        else{
            mp[str[i]] = {1, i};
        }
    }

    int ans = 100001;
    for(auto [c, t]: mp){
        if(t.first == 1){
            ans = min(ans, t.second);
        }
    }

    if(ans == 100001) cout << "None";
    else cout << str[ans];

    return 0;
}
