#include <iostream>
#include <unordered_map>

using namespace std;

struct Node{
    int idx;
    Node* next;
    Node* prev;

    Node(int idx){
        this->idx = idx;
        next = nullptr;
        prev = nullptr;
    }
};

int N, M;
int knight;
int call;

int main() {
    cin >> N >> M;

    unordered_map<int, Node*> knights;
    Node* prev = nullptr;
    Node* head = nullptr;
    for (int i = 0; i < N; i++) {
        cin >> knight;
        Node* newNode = new Node(knight);

        knights[knight] = newNode;
        if(i > 0) {
            newNode->prev = prev;
            prev->next = newNode;
        }

        if(i == 0) head = newNode;

        prev = newNode;
    }
    prev->next = head;
    head->prev = prev;

    for (int i = 0; i < M; i++) {
        cin >> call;

        Node* cur = knights[call];

        cout << cur->next->idx << " " << cur->prev->idx << endl;

        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;

        cur->next = nullptr;
        cur->prev = nullptr;
        
    }

    // Please write your code here.

    return 0;
}
