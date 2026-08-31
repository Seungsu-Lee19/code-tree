#include <iostream>
#include <tuple>
#include <algorithm>
#include <string>

using namespace std;

int n;
string name;
int score1;
int score2;
int score3;

bool cmp(const tuple<int, int, int, string> a, const tuple<int, int, int, string> b){
    return get<0>(a) + get<1>(a) + get<2>(a) < get<0>(b) + get<1>(b) + get<2>(b);
}

int main() {
    cin >> n;

    tuple<int, int, int, string> t[n];
    for (int i = 0; i < n; i++) {
        cin >> name;
        cin >> score1;
        cin >> score2;
        cin >> score3;

        t[i] = make_tuple(score1, score2, score3, name);
    }

    // Please write your code here.
    sort(t, t + n, cmp);
    for(int i = 0; i < n; i++){
        tie(score1, score2, score3, name) = t[i];
        cout << name << " " << score1 << " " << score2 << " " << score3 << endl;
    }

    return 0;
}