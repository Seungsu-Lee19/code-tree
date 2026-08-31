#include <iostream>
#include <tuple>
#include <algorithm>

using namespace std;

int N;
int h;
int w;

bool cmp(const tuple<int, int, int> a, const tuple<int, int, int> b){
    int h1, w1, idx1, h2, w2, idx2;
    tie(h1, w1, idx1) = a;
    tie(h2, w2, idx2) = b;

    if(h1 != h2){
        return h1 > h2;
    }

    if(w1 != w2){
        return w1 > w2;
    }

    return idx1 < idx2;
    
}

int main() {
    cin >> N;

    tuple<int, int, int> t[N];
    for (int i = 0; i < N; i++) {
        cin >> h >> w;
        t[i] = make_tuple(h, w, i + 1);
    }

    // Please write your code here.
    sort(t, t + N, cmp);
    int idx;
    for (int i = 0; i < N; i++) {
        tie(h, w, idx) = t[i];
        cout << h << " " << w << " " << idx << endl;
    }

    return 0;
}
