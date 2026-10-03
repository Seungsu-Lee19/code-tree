#include <iostream>
#include <vector>

using namespace std;

struct Node{
    int num;
    Node* prev;
    Node* next;

    Node(int num){
        this->num = num;
        prev = nullptr;
        next = nullptr;
    }
};

int N, M, Q;

int main() {
    cin >> N >> M >> Q;

    vector<Node*> people(N + 1, nullptr);
    vector<Node*> head(M + 1, nullptr);

    for(int i = 1; i <= N; i++){
        people[i] = new Node(i);
    }

    int num;
    int line_size;
    for (int i = 1; i <= M; i++) { // 어디 줄에
        cin >> line_size;
        if (line_size == -1) continue;

        Node* prev = nullptr;
        for (int j = 0; j < line_size; j++) { // 몇번이 들어가 있냐
            cin >> num;
            
            Node* cur = people[num];

            if(j == 0) head[i] = cur;

            if(prev != nullptr){
                prev->next = cur;
                cur->prev = prev;
            }

            prev = cur;
        }
    }

    
    int cmd, a, b, c;
    for (int i = 0; i < Q; i++) {
        cin >> cmd;
        if (cmd == 1) {
            cin >> a >> b;

            Node* A = people[a];
            Node* B = people[b];

            Node* nextA = A->next;

            if(A->next == B) continue;

            if(A->next != nullptr) A->next->prev = A->prev;
            if(A->prev != nullptr) A->prev->next = A->next;

            A->next = B;
            A->prev = B->prev;

            if(B->prev != nullptr) B->prev->next = A;
            B->prev = A;
            
            for(int line = 1; line <= M; line++){
                if(head[line] == A){
                    head[line] = nextA;
                }
                if(head[line] == B){
                    head[line] = A;
                }
            }
        } 
        else if (cmd == 2) {
            cin >> a;

            Node* A = people[a];

            if(A->next != nullptr) A->next->prev = A->prev;
            if(A->prev != nullptr) A->prev->next = A->next;

            for(int line = 1; line <= M; line++){
                if(head[line] == A){
                    head[line] = head[line]->next;
                }
            }
            A->next = nullptr;
            A->prev = nullptr;
        } 
        else if (cmd == 3) {
            cin >> a >> b >> c;

            Node* A = people[a];
            Node* B = people[b];
            Node* C = people[c];

            if(B->next == C) continue;

            Node* nextB = B->next;

            if(A->prev != nullptr) A->prev->next = B->next;
            if(B->next != nullptr) B->next->prev = A->prev;

            A->prev = C->prev;
            B->next = C;

            if(C->prev != nullptr) C->prev->next = A;
            C->prev = B;

            
            for(int line = 1; line <= M; line++){
                if(head[line] == A){
                    head[line] = nextB;
                }
                if(head[line] == C){
                    head[line] = A;
                }
            }
        }
    }

    for(int i = 1; i <= M; i++){
        Node* cur = head[i];

        if(cur == nullptr) cout << "-1\n";
        else{
            while(cur != nullptr){
                cout << cur->num << " ";
                cur = cur->next;
            }
            cout << "\n";
        }
    }

    return 0;
}
