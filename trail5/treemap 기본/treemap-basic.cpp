#include <iostream>
#include <string>
#include <map>

using namespace std;

int n;
string cmd;
int k;
int v;

int main() {
    cin >> n;

    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> cmd;
        if (cmd == "add") {
            cin >> k >> v;
            mp[k] = v;
        } 
        else if (cmd == "remove"){
            cin >> k;
            mp.erase(k);
        }
        else if(cmd == "find"){
            cin >> k;
            if(mp.find(k) != mp.end()) cout << mp[k] << endl;
            else cout << "None\n";
        }
        else{
            if(mp.empty()) {
                cout << "None\n";
                continue;
            }

            for(auto [key, value] : mp){
                cout << value << " ";
            }
            cout << "\n";
        }
    }

    // Please write your code here.

    return 0;
}
