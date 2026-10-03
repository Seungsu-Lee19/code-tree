#include <iostream>
#include <vector>

using namespace std;

int N, K, Q;

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

    cin >> N >> K;
    cin >> Q;

    vector<Node*> nodes(N + 1);
    vector<Node*> head(K + 1, nullptr);
    vector<Node*> tail(K + 1, nullptr);
    vector<int> cnt(K + 1, 0);

    // 책 생성
    for (int i = 1; i <= N; i++) {
        nodes[i] = new Node(i);
    }

    // 처음에는 모든 책이 1번 책꽂이에 있음
    for (int i = 1; i < N; i++) {
        nodes[i]->next = nodes[i + 1];
        nodes[i + 1]->prev = nodes[i];
    }

    head[1] = nodes[1];
    tail[1] = nodes[N];
    cnt[1] = N;

    int type, i, j;

    for (int t = 0; t < Q; t++) {
        cin >> type >> i >> j;

        // i의 맨 앞 책 -> j의 맨 뒤
        if (type == 1) {
            if (head[i] == nullptr)
                continue;

            Node* move = head[i];

            // i에서 제거
            head[i] = move->next;

            if (head[i] != nullptr) {
                head[i]->prev = nullptr;
            }
            else {
                tail[i] = nullptr;
            }

            move->prev = nullptr;
            move->next = nullptr;

            cnt[i]--;

            // j의 맨 뒤에 삽입
            if (tail[j] == nullptr) {
                head[j] = move;
                tail[j] = move;
            }
            else {
                tail[j]->next = move;
                move->prev = tail[j];
                tail[j] = move;
            }

            cnt[j]++;
        }

        // i의 맨 뒤 책 -> j의 맨 앞
        else if (type == 2) {
            if (tail[i] == nullptr)
                continue;

            Node* move = tail[i];

            // i에서 제거
            tail[i] = move->prev;

            if (tail[i] != nullptr) {
                tail[i]->next = nullptr;
            }
            else {
                head[i] = nullptr;
            }

            move->prev = nullptr;
            move->next = nullptr;

            cnt[i]--;

            // j의 맨 앞에 삽입
            if (head[j] == nullptr) {
                head[j] = move;
                tail[j] = move;
            }
            else {
                move->next = head[j];
                head[j]->prev = move;
                head[j] = move;
            }

            cnt[j]++;
        }

        // i의 모든 책 -> j의 맨 앞
        else if (type == 3) {
            if (head[i] == nullptr)
                continue;

            // 자기 자신 전체를 자기 앞에 옮기면 변화 없음
            if (i == j)
                continue;

            if (head[j] == nullptr) {
                head[j] = head[i];
                tail[j] = tail[i];
            }
            else {
                tail[i]->next = head[j];
                head[j]->prev = tail[i];

                head[j] = head[i];
            }

            cnt[j] += cnt[i];
            cnt[i] = 0;

            head[i] = nullptr;
            tail[i] = nullptr;
        }

        // i의 모든 책 -> j의 맨 뒤
        else if (type == 4) {
            if (head[i] == nullptr)
                continue;

            // 자기 자신 전체를 자기 뒤에 옮기면 변화 없음
            if (i == j)
                continue;

            if (head[j] == nullptr) {
                head[j] = head[i];
                tail[j] = tail[i];
            }
            else {
                tail[j]->next = head[i];
                head[i]->prev = tail[j];

                tail[j] = tail[i];
            }

            cnt[j] += cnt[i];
            cnt[i] = 0;

            head[i] = nullptr;
            tail[i] = nullptr;
        }
    }

    // 출력
    for (int i = 1; i <= K; i++) {
        cout << cnt[i];

        Node* cur = head[i];

        while (cur != nullptr) {
            cout << " " << cur->num;
            cur = cur->next;
        }

        cout << '\n';
    }

    return 0;
}