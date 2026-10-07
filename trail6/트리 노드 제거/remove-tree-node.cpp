#include <iostream>
#include <vector>

using namespace std;

int n, remove_node;
int root;
int ans = 0;

vector<vector<int>> child;

void dfs(int cur) {
    int cnt = 0;

    for (int next : child[cur]) {
        if (next == remove_node)
            continue;

        cnt++;
        dfs(next);
    }

    // 삭제되지 않은 자식이 없으면 리프 노드
    if (cnt == 0)
        ans++;
}

int main() {
    cin >> n;

    child.resize(n);

    for (int i = 0; i < n; i++) {
        int parent;
        cin >> parent;

        if (parent == -1)
            root = i;
        else
            child[parent].push_back(i);
    }

    cin >> remove_node;

    // 루트를 삭제하면 트리가 사라짐
    if (remove_node == root) {
        cout << 0;
        return 0;
    }

    dfs(root);

    cout << ans;

    return 0;
}