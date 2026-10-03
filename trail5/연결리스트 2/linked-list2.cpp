#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    // prev[i] : i번 노드의 이전 노드
    // next[i] : i번 노드의 다음 노드
    // 0이면 해당 노드가 없음
    vector<int> prev(N + 1, 0);
    vector<int> next(N + 1, 0);

    while (Q--) {
        int command, i, j;
        cin >> command >> i;

        // 1 i : i번 노드를 현재 연결 리스트에서 제거
        if (command == 1) {

            // i의 이전 노드와 다음 노드를 서로 연결
            if (prev[i] != 0) {
                next[prev[i]] = next[i];
            }

            if (next[i] != 0) {
                prev[next[i]] = prev[i];
            }

            // i는 다시 단일 노드가 됨
            prev[i] = 0;
            next[i] = 0;
        }

        // 2 i j : j를 i 바로 앞에 삽입
        else if (command == 2) {
            cin >> j;

            int p = prev[i];

            // 기존
            // p <-> i
            //
            // 변경
            // p <-> j <-> i

            prev[j] = p;
            next[j] = i;

            if (p != 0) {
                next[p] = j;
            }

            prev[i] = j;
        }

        // 3 i j : j를 i 바로 뒤에 삽입
        else if (command == 3) {
            cin >> j;

            int n = next[i];

            // 기존
            // i <-> n
            //
            // 변경
            // i <-> j <-> n

            next[j] = n;
            prev[j] = i;

            if (n != 0) {
                prev[n] = j;
            }

            next[i] = j;
        }

        // 4 i : i의 이전 노드와 다음 노드 출력
        else if (command == 4) {
            cout << prev[i] << " " << next[i] << '\n';
        }
    }

    // 각 노드의 다음 노드 출력
    for (int i = 1; i <= N; i++) {
        cout << next[i] << " ";
    }

    return 0;
}