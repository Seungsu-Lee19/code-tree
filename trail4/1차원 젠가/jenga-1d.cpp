#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> blocks;
int s1, e1;
int s2, e2;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        blocks.push_back(x);
    }

    cin >> s1 >> e1;
    cin >> s2 >> e2;

    // Please write your code here.
    s1--;
    s2--;
    e1--;
    e2--;

    blocks.erase(blocks.begin() + s1, blocks.begin() + e1 + 1);    
    // for(auto i : blocks){
    //     cout << i << endl;
    // }
    // cout << endl;

    blocks.erase(blocks.begin() + s2, blocks.begin() + e2 + 1);    

    cout << blocks.size() << endl;
    for(auto i : blocks){
        cout << i << endl;
    }
    

    return 0;
}
