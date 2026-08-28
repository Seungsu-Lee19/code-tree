#include <iostream>

using namespace std;

int n;

void func(int a){
    if(a == 0) return;

    func(a - 1);
    for(int i = 0; i < a; i++){
        cout << '*';
    }
    cout << "\n";
}

int main() {
    cin >> n;

    // Please write your code here.
    func(n);

    return 0;
}