#include <iostream>
#include <string>
#include <tuple>
#include <algorithm>

using namespace std;

int n;
string name;
int height;
int weight;

bool cmp(const tuple<int, int, int> a, const tuple<int, int, int> b){
    if(get<0>(a) != get<0>(b)){
        return get<0>(a) < get<0>(b);
    }

    return get<1>(a) > get<1>(b);
}

int main() {
    cin >> n;

    tuple<int, int, int> t[n];
    for (int i = 0; i < n; i++) {
        cin >> height >> weight;
        t[i] = make_tuple(height, weight, i + 1);
    }

    // Please write your code here.
    sort(t, t + n, cmp);
    int idx;
    for (int i = 0; i < n; i++) {
        tie(height, weight, idx) = t[i];
        cout << height << " " << weight << " " << idx << endl;
    }

    return 0;
}