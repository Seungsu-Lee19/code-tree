#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int t;
int m;
int arr;

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> m;


        // left는 최대 힙, right 최소 힙
        // left.size() == right.size(), 짝수
        // left.size() + 1 == right.size(), 홀수
        // 항상 left.top()이 중앙값
        // 즉, 오름차순 했을 때, left는 작은값들, right는 큰 값들
        // x가 left.top()보다 작다 => left 넣고, right로 옮겨
        // x가 left.top()보다 크다 => right 넣어
        // 근데 

        priority_queue<int> left;
        priority_queue<int, vector<int>, greater<int>> right;
        for (int j = 0; j < m; j++) {
            cin >> arr;

            left.push(arr);

            right.push(left.top());
            left.pop();

            if(left.size() < right.size()){
                left.push(right.top());
                right.pop();
            }

            if(j % 2 == 0) cout << left.top() << " ";
        }
        cout << endl;


    }

    return 0;
}
