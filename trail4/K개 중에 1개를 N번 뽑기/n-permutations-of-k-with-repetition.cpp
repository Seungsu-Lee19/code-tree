#include <iostream>

using namespace std;

int grid[10];

int K, N;

void print(){
    for(int i = 0; i < N; i++){
        cout << grid[i] << " ";
    }
    cout << endl;
}

void back(int cnt){
    if(cnt == N) {
        print();
        return;
    }

    for(int i = 1; i <= K; i++){
        grid[cnt] = i;
        back(cnt + 1);
    }
}

int main() {
    cin >> K >> N;

    // Please write your code here.

    back(0);

    return 0;
}
