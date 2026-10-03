#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int num;
    Node* prev;
    Node* next;

    Node(int num) {
        this->num = num;
        prev = nullptr;
        next = nullptr;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;


    vector<Node*> node(N + 1);
    // prev[i] : i번 노드의 이전 노드
    // next[i] : i번 노드의 다음 노드
    // 0이면 해당 노드가 없음
    for (int i = 1; i <= N; i++) {
        node[i] = new Node(i);
    }


    while (Q--) {
        int command, i, j;
        cin >> command >> i;

        // 1 i : i번 노드를 현재 연결 리스트에서 제거
        if (command == 1) {
            Node *cur = node[i];

            if(cur->prev != nullptr){
                cur->prev->next = cur->next;
            }
            if(cur->next != nullptr){
                cur->next->prev = cur->prev;
            }

            cur->next = nullptr;
            cur->prev = nullptr;
        }

        // 2 i j : j를 i 바로 앞에 삽입
        else if (command == 2) {
            cin >> j;

            Node *cur = node[i];
            Node *add = node[j];

            add->prev = cur->prev;
            add->next = cur;

            if(cur->prev != nullptr){
                cur->prev->next = add;
            }
            cur->prev = add;
        }

        // 3 i j : j를 i 바로 뒤에 삽입
        else if (command == 3) {
            cin >> j;

            Node *cur = node[i];
            Node *add = node[j];

            add->prev = cur;
            add->next = cur->next;

            if(cur->next != nullptr){
                cur->next->prev = add;
            }
            cur->next = add;
        }

        // 4 i : i의 이전 노드와 다음 노드 출력
        else if (command == 4) {
            Node *cur = node[i];

            if(cur->prev == nullptr) cout << "0 ";
            else cout << cur->prev->num << " ";

            if(cur->next == nullptr) cout << "0\n";
            else cout << cur->next->num << endl;
        }
    }

    // 각 노드의 다음 노드 출력
    for (int i = 1; i <= N; i++) {
        Node *cur = node[i];

        if(cur->next == nullptr) cout << "0 ";
        else cout << cur->next->num << " ";
    }

    return 0;
}