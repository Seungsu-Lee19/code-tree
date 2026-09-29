#include <iostream>
#include <unordered_set>

using namespace std;

int n;
string command;
int x;

int main() {
    cin >> n;

    unordered_set<int> se;
    for (int i = 0; i < n; i++) {
        cin >> command >> x;
        if(command == "add"){
            se.insert(x);
        }
        else if(command == "remove"){
            se.erase(x);
        }
        else{
            if(se.find(x) != se.end()) cout << "true\n";
            else cout << "false\n";
        }
    }

    // Please write your code here.

    return 0;
}
