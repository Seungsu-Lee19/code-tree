
#include <iostream>
using namespace std;

int N;
char leftChild[26], rightChild[26];

void preorder(char node) {
    if (node == '.') return;

    cout << node;
    preorder(leftChild[node - 'A']);
    preorder(rightChild[node - 'A']);
}

void inorder(char node) {
    if (node == '.') return;

    inorder(leftChild[node - 'A']);
    cout << node;
    inorder(rightChild[node - 'A']);
}

void postorder(char node) {
    if (node == '.') return;

    postorder(leftChild[node - 'A']);
    postorder(rightChild[node - 'A']);
    cout << node;
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        char node, left, right;
        cin >> node >> left >> right;

        leftChild[node - 'A'] = left;
        rightChild[node - 'A'] = right;
    }

    preorder('A');
    cout << '\n';

    inorder('A');
    cout << '\n';

    postorder('A');
    cout << '\n';

    return 0;
}
