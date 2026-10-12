
#include <iostream>
#include <vector>
using namespace std;

int K;
vector<int> arr;
vector<vector<int>> tree;

void dfs(int left, int right, int depth) {
    if (left > right) return;

    int mid = (left + right) / 2;

    tree[depth].push_back(arr[mid]);

    dfs(left, mid - 1, depth + 1);
    dfs(mid + 1, right, depth + 1);
}

int main() {
    cin >> K;

    int N = (1 << K) - 1;

    arr.resize(N);
    tree.resize(K);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    dfs(0, N - 1, 0);

    for (int i = 0; i < K; i++) {
        for (int x : tree[i]) {
            cout << x << " ";
        }
        cout << '\n';
    }

    return 0;
}
