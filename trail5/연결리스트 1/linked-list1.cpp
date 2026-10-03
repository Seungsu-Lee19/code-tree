#include <iostream>
#include <list>
#include <string>
#include <iterator>

using namespace std;

string S_init;
int N;
int command;
string S_value;

int main() {
    cin >> S_init;
    cin >> N;

    list<string> li;
    li.push_back(S_init);

    auto cur = li.begin();

    for (int i = 0; i < N; i++) {
        cin >> command;
        if (command == 1) {
            cin >> S_value;

            li.insert(cur, S_value);
        }
        else if (command == 2) {
            cin >> S_value;

            li.insert(next(cur), S_value);
        }
        else if (command == 3) {
            if(cur != li.begin()) --cur;
        }
        else if (command == 4) {
            if(next(cur) != li.end()) ++cur;
        }

        string p = "(Null)";
        string c = *cur;
        string n = "(Null)";

        if(cur != li.begin()) p = *prev(cur);
        if(next(cur) != li.end()) n = *next(cur);

        cout << p << " " << c << " " << n << endl;
    }

    // Please write your code here.

    return 0;
}
