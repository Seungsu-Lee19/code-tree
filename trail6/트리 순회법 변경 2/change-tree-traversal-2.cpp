
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int n;
vector<int> pre, in;
unordered_map<int, int> pos;

void build(int preL, int preR, int inL, int inR) {
    if (preL > preR) return;

    // 1. 전위 순회의 첫 번째 값이 루트
    int root = pre[preL];

    // 2. 중위 순회에서 루트의 위치 찾기
    int mid = pos[root];

    // 3. 왼쪽 서브트리의 노드 개수
    int leftSize = mid - inL;

    // 4. 왼쪽 서브트리
    build(preL + 1, preL + leftSize,
          inL, mid - 1);

    // 5. 오른쪽 서브트리
    build(preL + leftSize + 1, preR,
          mid + 1, inR);

    // 6. 후위 순회 출력
    cout << root << " ";
}

int main() {
    cin >> n;

    pre.resize(n);
    in.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> pre[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> in[i];
        pos[in[i]] = i;
    }

    build(0, n - 1, 0, n - 1);

    return 0;
}
