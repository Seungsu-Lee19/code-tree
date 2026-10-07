#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int n, k;
int sequence[1000];

int main() {
    cin >> n >> k;

    int root, parent;
    map<int, int> parents;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> sequence[i];

        if(i == 0) {
            root = sequence[i];
            parent = root;
        }
        else if(i == 1){
            parents[sequence[i]] = parent;
            cnt++;
        }
        else{
            if(sequence[i] - sequence[i - 1] != 1){
                parent = sequence[i - cnt];
                cnt--;
            }

            cnt++;
            parents[sequence[i]] = parent;
        }
    }

    // for(auto [c, p]: parents){
    //     cout << c << " -> " << p << endl;
    // }
    // cout << endl;

    // map<int, vector<int>> parents;
    // parents[자식] == 부모

    parent = parents[k];
    int grand_parent = -1;
    if(parents.find(parent) != parents.end()) grand_parent = parents[parent];
    else{
        cout << 0;
        return 0;
    }

    int ans = 0;
    for(auto [c, p]: parents){
        if(p != parent && parents[p] == grand_parent) ans++;
    }

    cout << ans;

    return 0;
}