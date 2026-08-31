#include <iostream>
#include <tuple>
#include <algorithm>

using namespace std;

int n;
string name[10];
int height[10];
int weight[10];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> name[i];
        cin >> height[i];
        cin >> weight[i];
    }

    // Please write your code here.
    tuple<int, int, string> t[n];
    for (int i = 0; i < n; i++) {
        t[i] = make_tuple(height[i], weight[i], name[i]);
    }
    sort(t, t + n);

    for (int i = 0; i < n; i++) {
        int h, w;
        string n;
        tie(h, w, n) = t[i];

        cout << n << " " << h << " " << w << endl;
    }


    return 0;
}