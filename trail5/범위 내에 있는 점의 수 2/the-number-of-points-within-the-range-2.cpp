#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, Q;

int main() {
    cin >> N >> Q;

    vector<int> points(N);
    for (int i = 0; i < N; i++) {
        cin >> points[i];
    }
    sort(points.begin(), points.end());
    int max_idx = points.back();

    vector<int> sum(max_idx + 1);

    for(int i = 0; i < N; i++){
        for(int p = points[i]; p <= points[i + 1]; p++){
            sum[p] = i + 1;
        }
    }
    sum[max_idx]++;

    int A, B;
    for (int i = 0; i < Q; i++) {
        cin >> A >> B;
        if(A > max_idx) {
            cout << "0\n";
            continue;
        }

        if(B > max_idx) B = max_idx;
        cout << sum[B] - sum[A - 1] << endl;
    }


    return 0;
}
