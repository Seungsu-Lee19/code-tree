#include <iostream>

using namespace std;

int N;

int main() {
    cin >> N;

    // Please write your code here.
    int k = 1;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << k << " ";
            k = (k + 1) % 10;
            if(k == 0) k = 1;
        }
        cout << "\n";
    }

    return 0;
}