#include <iostream>
#include <tuple>
#include <algorithm>

using namespace std;

int N;
int x;
int y;

bool cmp(const tuple<int, int, int> a, const tuple<int, int, int> b){
    int x1, y1, idx1, x2, y2, idx2;
    tie(x1, y1, idx1) = a;
    tie(x2, y2, idx2) = b;

    if(abs(x1) + abs(y1) != abs(x2) + abs(y2)){
        return abs(x1) + abs(y1) < abs(x2) + abs(y2);
    }

    return idx1 < idx2;
}

int main() {
    cin >> N;

    tuple<int, int, int> p[N];
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        p[i] = make_tuple(x, y, i + 1);
    }

    // Please write your code here.
    sort(p, p + N, cmp);
    
    int idx;
    for (int i = 0; i < N; i++) {
        tie(x, y, idx) = p[i];
        cout << idx << endl;
    }

    return 0;
}
