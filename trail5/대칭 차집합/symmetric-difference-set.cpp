#include <iostream>
#include <unordered_set>

using namespace std;

int n, m;
int A[200000];
int B[200000];

int main() {
    cin >> n >> m;

    int x;
    unordered_set<int> se1;
    for (int i = 0; i < n; i++) {
        cin >> x;
        se1.insert(x);
    }

    unordered_set<int> se2;
    for (int i = 0; i < m; i++) {
        cin >> x;
        se2.insert(x);
    }
    // Please write your code here.

    unordered_set<int> temp = se1;
    for(auto i : se2){
        se1.erase(i);
    }

    for(auto i : temp){
        se2.erase(i);
    }

    se1.insert(se2.begin(), se2.end());
    cout << se1.size();
    return 0;
}
