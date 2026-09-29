#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>

using namespace std;

int N, K;
int a[100000], b[100000];

int main() {
    cin >> N >> K;
    for (int i = 0; i < K; i++) {
        cin >> a[i] >> b[i];
    }

    // Please write your code here.
    vector<unordered_set<int>> mp(N + 1);
    vector<int> people(N + 1);
    
    for(int i = 1; i <= N; i++){
        people[i] = i;
        mp[i].insert(i);
    }

    for(int i = 0; i < 3 * K; i++){
        int idx = i % K;

        mp[people[a[idx]]].insert(b[idx]);
        mp[people[b[idx]]].insert(a[idx]);

        swap(people[a[idx]], people[b[idx]]);
    }

    for(int i = 1; i <= N; i++){
        cout << mp[i].size() << endl;
    }

    return 0;
}
