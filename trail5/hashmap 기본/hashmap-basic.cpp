#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int n;
string cmd;
int k;
int v;

int main() {
    cin >> n;

    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++) {
        cin >> cmd;
        cin >> k;

        if (cmd == "add") {
            cin >> v;
            mp[k] = v;
        }
        else if(cmd == "remove"){
            mp.erase(k);
        }
        else if(cmd == "find"){
            if(mp.find(k) == mp.end()) cout << "None\n";
            else cout << mp[k] << endl;
        }
    }

    // Please write your code here.

    return 0;
}
