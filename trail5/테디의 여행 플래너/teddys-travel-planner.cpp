#include <iostream>
#include <string>
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

int N, Q;
string cities;
int option;
string new_city;

int main() {
    cin >> N >> Q;

    cin >> cities;
    Node* head = new Node(cities);
    Node* cur = head;

    for (int i = 1; i < N; i++) {
        cin >> cities;
        Node* newNode = new Node(cities);

        cur->next = newNode;
        newNode->prev = cur;

        cur = newNode;
    }
    cur->next = head;
    head->prev = cur;

    cur = head;

    for (int i = 0; i < Q; i++) {
        cin >> option;
        if (option == 1) {
            if(cur->next != nullptr) cur = cur->next;
        }
        else if (option == 2) {
            if(cur->prev != nullptr) cur = cur->prev;
        }
        else if (option == 3) {
            if(cur->next == nullptr) continue;

            Node* del = cur->next;

            if(del->next != nullptr) {
                cur->next = del->next;
                del->next->prev = cur;
            }

            del->next = nullptr;
            del->prev = nullptr;
            
        }
        else if (option == 4) {
            cin >> new_city;

            Node* newNode = new Node(new_city);

            newNode->prev = cur;
            newNode->next = cur->next;
            cur->next->prev = newNode;
            cur->next = newNode;
        }

        Node* left = cur->prev;
        Node* right = cur->next;

        if(left == nullptr || right == nullptr) cout << "-1\n";
        else if(left->name == right->name) cout << "-1\n";
        else{
            cout << left->name << " " << right->name << endl;
        }
    }

    // Please write your code here.

    return 0;
}
