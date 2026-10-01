#include <iostream>
#include <string>
#include <queue>

using namespace std;

int N;
string command;

int main() {
    cin >> N;

    priority_queue<int> pq;

    for (int i = 0; i < N; i++) {
        cin >> command;
        if (command == "push") {
            int x;
            cin >> x;

            pq.push(x);
        }
        else if(command == "pop"){
            cout << pq.top() << endl;
            pq.pop();
        }
        else if(command == "size"){
            cout << pq.size() << endl;
        }
        else if(command == "empty"){
            if(pq.empty()) cout << "1\n";
            else cout << "0\n";
        }
        else if(command == "top"){
            cout << pq.top() << endl;
        }
    }

    // Please write your code here.

    return 0;
}
