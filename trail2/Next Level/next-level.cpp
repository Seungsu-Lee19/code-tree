#include <iostream>
#include <string>
#include <utility>

using namespace std;

string user2_id;
int user2_level;

int main() {
    cin >> user2_id >> user2_level;

    // Please write your code here.
    pair<string, int> p = make_pair("codetree", 10);

    cout << "user " << p.first << " lv " << p.second << endl;
    
    p.first = user2_id;
    p.second = user2_level;
    cout << "user " << p.first << " lv " << p.second << endl;

    return 0;
}