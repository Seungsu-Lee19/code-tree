#include <iostream>

using namespace std;

int n;

void func(int n){
    if(n == 0) return;

    for(int i = 0; i < n; i++){
        cout << "* ";
    }
    cout << "\n";
    func(n - 1);
    for(int i = 0; i < n; i++){
        cout << "* ";
    }
    cout << "\n";

}

int main() {
    cin >> n;

    // Please write your code here.
    func(n);
    return 0;
}