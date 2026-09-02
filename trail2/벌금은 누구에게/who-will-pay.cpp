#include <iostream>

using namespace std;

int N, M, K;

int main() {
    cin >> N >> M >> K;

    int student[N + 1] = {0, };
    int who[M];
    for (int i = 0; i < M; i++) {
        cin >> who[i];
    }

    // Please write your code here.
    int ans = -1;
    for (int i = 0; i < M; i++) {
        student[who[i]]++;

        if(student[who[i]] >= K) {
            ans = who[i];
            break;
        }
    }

    cout << ans;

    return 0;
}