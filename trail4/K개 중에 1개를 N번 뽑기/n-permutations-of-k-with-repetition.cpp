#include <iostream>

using namespace std;

int K, N;
int arr[10];

void print() {
    for(int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void dfs(int cnt) {
    // N개의 숫자를 모두 골랐으면 출력
    if(cnt == N) {
        print();
        return;
    }

    // 현재 위치에 1 ~ K를 하나씩 선택
    for(int i = 1; i <= K; i++) {
        arr[cnt] = i;
        dfs(cnt + 1);
    }
}

int main() {
    cin >> K >> N;

    dfs(0);

    return 0;
}