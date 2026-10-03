#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct Node{
    string name;
    Node* prev;
    Node* next;

    Node(string name){
        this->name = name;
        prev = nullptr;
        next = nullptr;
    }
};

int N, M, Q;
string names;
int command;
string a, b, c;

int main() {
    cin >> N >> M >> Q;

    unordered_map<string, Node*> people;
    vector<Node*> head(M);
    vector<Node*> tail(M);

    int x = N / M;
    for (int i = 1; i <= N; i++) {
        cin >> names;
        people[names] = new Node(names);

        int line = (i - 1) / x;
        if((i - 1) % x == 0){
            head[line] = people[names];
            tail[line] = people[names];
        }
        else{
            people[names]->prev = tail[line];
            tail[line]->next = people[names];

            tail[line] = people[names];
        }
    }

    for (int i = 0; i < Q; i++) {
        cin >> command;
        if (command == 1) {
            cin >> a >> b;

            Node* A = people[a];
            Node* B = people[b];

            Node* nextA = A->next;

            if(A->prev != nullptr) A->prev->next = A->next;
            if(A->next != nullptr) A->next->prev = A->prev;

            if(B->prev != nullptr) B->prev->next = A;
            A->prev = B->prev;
            A->next = B;
            B->prev = A;

            for(int i = 0; i < M; i++){
                if(head[i] == A) head[i] = nextA;
                if(head[i] == B) head[i] = A;
            }

        } 
        else if (command == 2) {
            cin >> a;

            Node* A = people[a];
            Node* nextA = A->next;

            if(A->next) A->next->prev = A->prev;
            if(A->prev) A->prev->next = A->next;

            A->next = nullptr;
            A->prev = nullptr;

            for(int i = 0; i < M; i++){
                if(head[i] == A) {
                    head[i] = nextA;
                    break;
                }
            }
        } 
        else {
            cin >> a >> b >> c;

            Node* A = people[a];
            Node* B = people[b];
            Node* C = people[c];

            Node* nextB = B->next;

            if(A->prev) A->prev->next = B->next;
            if(B->next) B->next->prev = A->prev;

            A->prev = C->prev;
            B->next = C;

            if(C->prev) C->prev->next = A;
            C->prev = B;
        
            for(int i = 0; i < M; i++){
                if(head[i] == A) head[i] = nextB;
                if(head[i] == C) head[i] = A;
            }
        }
    }

    for(int i = 0; i < M; i++){
        Node* cur = head[i];

        if(cur == nullptr) cout << "-1\n";
        else{
            while(cur != nullptr){
                cout << cur->name << " ";
                cur = cur->next;
            }
            cout << "\n";
        }
    }

    return 0;
}
