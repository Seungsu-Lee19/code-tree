#include <iostream>
#include <unordered_set>

using namespace std;

const int MAX_N = 100000;
int n;
int arr;

int main() {
    cin >> n;

    unordered_set<int> se;
    for (int i = 0; i < n; i++) {
        cin >> arr;
        se.insert(arr);
    }

    cout << se.size();
    // Please write your code here.

    return 0;
}
