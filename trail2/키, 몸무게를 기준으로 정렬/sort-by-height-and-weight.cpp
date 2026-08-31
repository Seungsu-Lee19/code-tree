#include <iostream>
#include <string>
#include <tuple>
#include <algorithm>

using namespace std;

int n;
string name;
int height;
int weight;

bool cmp(const tuple<int, int, string> a, const tuple<int, int, string> b){
    if(get<0>(a) != get<0>(b)){
        return get<0>(a) < get<0>(b);
    }

    return get<1>(a) > get<1>(b);
}

int main() {
    cin >> n;

    tuple<int, int, string> t[n];
    for (int i = 0; i < n; i++) {
        cin >> name >> height >> weight;
        t[i] = make_tuple(height, weight, name);
    }

    // Please write your code here.
    sort(t, t + n, cmp);
    for (int i = 0; i < n; i++) {
        tie(height, weight, name) = t[i];
        cout << name << " " << height << " " << weight << endl;
    }

    return 0;
}