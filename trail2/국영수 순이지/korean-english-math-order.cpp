#include <iostream>
#include <string>
#include <tuple>
#include <algorithm>

using namespace std;

int n;

int main() {
    cin >> n;
    
    int korean, english, math;
    string name;
    tuple<int, int, int, string> t[n];

    for (int i = 0; i < n; i++) {
        cin >> name;
        cin >> korean;
        cin >> english;
        cin >> math;

        t[i] = make_tuple(-korean, -english, -math, name);
    }

    // Please write your code here.
    sort(t, t + n);
    for (int i = 0; i < n; i++) {
        tie(korean, english, math, name) = t[i];
        cout << name << " " << -korean << " " << -english << " " << -math << endl;
    }


    return 0;
}