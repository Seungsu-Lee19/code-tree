#include <iostream>
#include <string>

using namespace std;

int n, m;
string s;

int main() {
    cin >> n >> m;
    cin >> s;

    int idx = s.length();
    char command;

    for (int i = 0; i < m; i++) {
        cin >> command;

        if (command == 'P') {
            char c;
            cin >> c;

            s.insert(idx, 1, c);
            idx++;
        }
        else if(command == 'L'){
            if(idx <= 0) continue;
            idx--;
        }
        else if(command == 'R'){
            if(idx >= s.length()) continue;
            idx++;
        }
        else if(command == 'D'){
            if(idx >= s.length()) continue;
            s.erase(idx, 1);
        }
    }

    // Please write your code here.
    cout << s;

    return 0;
}
