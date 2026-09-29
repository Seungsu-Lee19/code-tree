#include <iostream>
#include <set>

using namespace std;

int n;
string command;
int x;

int main() {
    cin >> n;

    set<int> se;
    for (int i = 0; i < n; i++) {
        cin >> command;
        if (command == "add") {
            cin >> x;
            se.insert(x);
        }
        else if (command == "remove") {
            cin >> x;
            se.erase(x);
        }
        else if (command == "find") {
            cin >> x;
            if(se.find(x) != se.end()) cout << "true\n";
            else cout << "false\n";
        }
        else if (command == "lower_bound") {
            cin >> x;
            auto it = se.lower_bound(x);
            if(it == se.end()) cout << "None\n";
            else cout << *it << endl;
        }
        else if (command == "upper_bound") {
            cin >> x;
            auto it = se.upper_bound(x);
            if(it == se.end()) cout << "None\n";
            else cout << *it << endl;
        }
        else if (command == "largest") {
            if(se.empty()) cout << "None\n";
            else cout << *se.rbegin() << endl;
        }
        else if (command == "smallest") {
            if(se.empty()) cout << "None\n";
            else cout << *se.begin() << endl;
        }
        
    }

    // Please write your code here.

    return 0;
}
