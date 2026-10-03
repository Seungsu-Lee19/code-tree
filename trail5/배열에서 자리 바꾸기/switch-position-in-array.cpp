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

    // 1 ~ N DLL 생성
    for (int i = 1; i <= N; i++) {
        node[i] = new Node(i);

        if (i > 1) {
            node[i]->prev = node[i - 1];
            node[i - 1]->next = node[i];
        }
    }

    while (Q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        Node* A = node[a];
        Node* B = node[b];
        Node* C = node[c];
        Node* D = node[d];

        // 각 구간 바깥쪽 노드 저장
        Node* beforeA = A->prev;
        Node* afterB = B->next;

        Node* beforeC = C->prev;
        Node* afterD = D->next;

        // [A ... B]가 [C ... D] 바로 앞에 붙어있는 경우
        if (afterB == C) {
            if (beforeA != nullptr)
                beforeA->next = C;
            C->prev = beforeA;

            D->next = A;
            A->prev = D;

            B->next = afterD;
            if (afterD != nullptr)
                afterD->prev = B;
        }

        // [C ... D]가 [A ... B] 바로 앞에 붙어있는 경우
        else if (afterD == A) {
            if (beforeC != nullptr)
                beforeC->next = A;
            A->prev = beforeC;

            B->next = C;
            C->prev = B;

            D->next = afterB;
            if (afterB != nullptr)
                afterB->prev = D;
        }

        // 두 구간 사이에 다른 노드가 있는 경우
        else {
            // A 앞 <-> C
            if (beforeA != nullptr)
                beforeA->next = C;
            C->prev = beforeA;

            // D <-> B 뒤
            D->next = afterB;
            if (afterB != nullptr)
                afterB->prev = D;

            // C 앞 <-> A
            if (beforeC != nullptr)
                beforeC->next = A;
            A->prev = beforeC;

            // B <-> D 뒤
            B->next = afterD;
            if (afterD != nullptr)
                afterD->prev = B;
        }
    }

    // head 찾기
    Node* head = nullptr;

    for (int i = 1; i <= N; i++) {
        if (node[i]->prev == nullptr) {
            head = node[i];
            break;
        }
    }

    // 최종 배열 출력
    while (head != nullptr) {
        cout << head->num << " ";
        head = head->next;
    }

    return 0;
}