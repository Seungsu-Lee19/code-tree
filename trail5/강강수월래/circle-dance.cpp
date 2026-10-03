#include <iostream>
#include <unordered_map>

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
int circle_size;
int student_nums;
int command;
int a, b;

int main() {
    cin >> N >> M >> Q;

    unordered_map<int, Node*> student;

    for (int i = 0; i < M; i++) {
        cin >> circle_size;
        
        Node* prev = nullptr;
        Node* start = nullptr;
        for (int j = 0; j < circle_size; j++) {
            cin >> student_nums;

            student[student_nums] = new Node(student_nums);
            if(prev != nullptr){
                prev->next = student[student_nums];
                student[student_nums]->prev = prev;
            }
            else start = student[student_nums];

            prev = student[student_nums];
        }
        prev->next = start;
        start->prev = prev;
    }

    for (int i = 0; i < Q; i++) {
        cin >> command;
        if (command == 1) {
            cin >> a >> b;

            Node* A = student[a];
            Node* B = student[b];

            B->prev->next = A->next;
            A->next->prev = B->prev;

            A->next = B;
            B->prev = A;
        } 
        else if(command == 2){
            cin >> a >> b;

            Node* A = student[a];
            Node* B = student[b];

            Node* prevB = B->prev;

            A->prev->next = B;
            B->prev = A->prev;

            A->prev = prevB;
            prevB->next = A;
        }
        else {
            cin >> a;

            Node* cur = student[a];
            Node* start = student[a];
            int idx = 100000000;

            while(1){
                if(cur->num < idx){
                    idx = cur->num;
                    start = cur;
                }
                cur = cur->next;

                if(cur == start) break;
            }

            Node* end = start;
            while(1){
                cout << start->num << " ";
                start = start->prev;

                if(end == start) break;
            }
        }
    }

    // Please write your code here.

    return 0;
}
