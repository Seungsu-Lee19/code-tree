#include <iostream>

using namespace std;

int n;
int pre_order[10000];

void dfs(int l, int r){
    if(l > r) return;

    int root = pre_order[l];
    int mid = r + 1;

    for(int i = l + 1; i <= r; i++){
        if(root < pre_order[i]){
            mid = i;
            break;
        }
    }

    dfs(l + 1, mid - 1);
    dfs(mid, r);
    cout << root << "\n";
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> pre_order[i];
    }
    dfs(0, n - 1);

    return 0;
}