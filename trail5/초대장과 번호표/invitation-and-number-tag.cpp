#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int N, G;

int main() {
    cin >> N >> G;

    int a, b;
    vector<vector<int>> v(G);
    for (int i = 0; i < G; i++) {
        cin >> a;
        for (int j = 0; j < a; j++) {
            cin >> b;
            v[i].push_back(b);
        }
    }

    // Please write your code here.
    unordered_set<int> se;
    se.insert(1);
    int prev_size = 1;

    while(1){
        for(int i = 0; i < G; i++){
            int invited = 0;
            int invite_person;
            for(auto p: v[i]){
                if(se.find(p) != se.end()) invited++;
                else invite_person = p;
            }

            if(invited == v[i].size() - 1){
                se.insert(invite_person);
            }
        }

        if(se.size() == prev_size) break;
        else prev_size = se.size();
    }

    cout << se.size();

    return 0;
}
