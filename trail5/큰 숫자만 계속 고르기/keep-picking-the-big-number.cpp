#include <iostream>
#include <queue>

using namespace std;

int n, m;
int arr;

int main() {
    cin >> n >> m;

    priority_queue<int> pq;

    for (int i = 0; i < n; i++) {
        cin >> arr;
        pq.push(arr);
    }

    for(int i = 0; i < m; i++){
        int q = pq.top();
        pq.pop();

        pq.push(q - 1);
    }

    cout << pq.top();
    // Please write your code here.

    return 0;
}
