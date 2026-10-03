#include <iostream>
#include <unordered_map>

using namespace std;

struct Node{
    int idx;
    Node* prev;
    Node* next;

    Node(int idx){
        this->idx = idx;
        prev = nullptr;
        next = nullptr;
    }
};

int Q;
int option;
int a;
int b;

int main() {
    cin >> Q;

    unordered_map<int, Node*> student;
    student[1] = new Node(1);
    int numOfstudent = 2;

    for (int i = 0; i < Q; i++) {
        cin >> option;
        if (option == 1) {
            cin >> a >> b;

            Node* cur = new Node(numOfstudent);
            student[numOfstudent] = cur;

            for(int s = numOfstudent + 1; s < numOfstudent + b; s++){
                student[s] = new Node(s);

                student[s]->prev = cur;
                cur->next = student[s];

                cur = student[s];
            }

            Node* A = student[a];

            student[numOfstudent]->prev = A;
            student[numOfstudent + b - 1]->next = A->next;
            if(A->next != nullptr) A->next->prev = student[numOfstudent + b - 1];
            A->next = student[numOfstudent];

            numOfstudent = numOfstudent + b;
        } 
        else if(option == 2){
            cin >> a >> b;

            Node* cur = new Node(numOfstudent);
            student[numOfstudent] = cur;

            for(int s = numOfstudent + 1; s < numOfstudent + b; s++){
                student[s] = new Node(s);

                student[s]->prev = cur;
                cur->next = student[s];

                cur = student[s];
            }

            Node* A = student[a];

            student[numOfstudent]->prev = A->prev;
            student[numOfstudent + b - 1]->next = A;
            if(A->prev != nullptr) A->prev->next = student[numOfstudent];
            A->prev = student[numOfstudent + b - 1];

            numOfstudent = numOfstudent + b;
        }
        else {
            cin >> a;

            Node* cur = student[a];
            if(cur->prev == nullptr || cur->next == nullptr) cout << "-1\n";
            else cout << cur->prev->idx << " " << cur->next->idx << endl;
        }
    }

    // Please write your code here.

    return 0;
}
