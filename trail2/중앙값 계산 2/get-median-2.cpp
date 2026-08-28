#include <iostream>
#include <queue>
using namespace std;

int main() {
    int N;
    cin >> N;

    priority_queue<int> left;  // 최대 힙
    priority_queue<int, vector<int>, greater<int>> right;  // 최소 힙

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;

        if (left.empty() || x <= left.top()) {
            left.push(x);
        }
        else {
            right.push(x);
        }

        // left의 원소가 right보다 많도록 조정
        if (left.size() < right.size()) {
            left.push(right.top());
            right.pop();
        }
        else if (left.size() > right.size() + 1) {
            right.push(left.top());
            left.pop();
        }

        // 홀수 번째 입력일 때 중앙값 출력
        if (i % 2 == 0) {
            cout << left.top() << ' ';
        }
    }

    return 0;
}