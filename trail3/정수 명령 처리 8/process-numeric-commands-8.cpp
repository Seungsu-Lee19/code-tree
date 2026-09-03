#include <iostream>
#include <string>
#include <list>

using namespace std;

int N;
string command;
int A;

int main() {
    cin >> N;

    list<int> l;

    for (int i = 0; i < N; i++) {
        cin >> command;

        if (command == "push_front") {
            cin >> A;
            l.push_front(A);
        }
        else if (command == "push_back") {
            cin >> A;
            l.push_back(A);
        }
        else if (command == "pop_front") {
            cout << l.front() << endl;
            l.pop_front();
        }
        else if (command == "pop_back") {
            cout << l.back() << endl;
            l.pop_back();
        }
        else if (command == "size") {
            cout << l.size() << endl;
        }
        else if (command == "empty") {
            cout << l.empty() << endl;
        }
        else if (command == "front") {
            cout << l.front() << endl;
        }
        else if (command == "back") {
            cout << l.back() << endl;
        }
        
    }

    // Please write your code here.

    return 0;
}
