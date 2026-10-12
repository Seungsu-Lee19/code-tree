#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int n;

vector<int> pre, in;
unordered_map<int, int> pos;

void dfs(int preL, int preR, int inL, int inR){
    if(preL > preR) return;

    int root = pre[preL];
    int mid = pos[root];
    int left_size = mid - inL;

    dfs(preL + 1, preL + left_size, inL, mid - 1);
    dfs(preL + left_size + 1, preR, mid + 1, inR);

    cout << root << " ";
}

int main() {
    cin >> n;

    pre.resize(n);
    in.resize(n);

    for (int i = 0; i < n; i++) cin >> pre[i];

    for (int i = 0; i < n; i++) {
        cin >> in[i];
        pos[in[i]] = i;
    }

    dfs(0, n - 1, 0, n - 1);

    return 0;
}