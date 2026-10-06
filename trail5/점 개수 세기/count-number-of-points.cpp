#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;

    vector<int> vec;
    for (int i = 0; i < n; i++) {
        int point;
        cin >> point;
        vec.push_back(point);
    }
    sort(vec.begin(), vec.end());


    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;

        auto left = lower_bound(vec.begin(), vec.end(), a);
        auto right = lower_bound(vec.begin(), vec.end(), b);

        if(*left > b) cout << "0\n";
        else{
            if(*right > b || right == vec.end()) right--;

            cout << right - left + 1 << "\n";
            // cout << *left << " " << *right << "\n\n";
        }
    }

    // Please write your code here.

    return 0;
}
