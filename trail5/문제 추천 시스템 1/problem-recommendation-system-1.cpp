#include <iostream>
#include <string>
#include <set>
#include <utility>
#include <map>

using namespace std;

int n, m;

int main() {
    cin >> n;

    map<int, set<int>> mp;

    int P, L;
    for (int i = 0; i < n; i++) {
        cin >> P >> L;
        mp[L].insert(P);
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        string command;
        cin >> command;

        if (command == "rc") {
            int x;
            cin >> x;

            if(x > 0){
                cout << *mp.rbegin()->second.rbegin() << endl;
            }
            else{
                cout << *mp.begin()->second.begin() << endl;
            }
        } else if (command == "ad") {
            int p, l;
            cin >> p >> l;

            mp[l].insert(p);

        } else if (command == "sv") {
            int p, l;
            cin >> p >> l;

            mp[l].erase(p);
            if(mp[l].empty()) mp.erase(l);
        }
    }

    // Please write your code here.

    return 0;
}
