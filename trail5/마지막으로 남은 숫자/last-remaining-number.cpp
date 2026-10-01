#include <iostream>
#include <queue>

using namespace std;

int n;
int arr;

int main() {
    cin >> n;

    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        cin >> arr;
        pq.push(arr);
    }

    while(pq.size() >= 2){
        int x = pq.top();
        pq.pop();

        int y = pq.top();
        pq.pop();

        if(x - y > 0) pq.push(x - y);
    }

    if(pq.empty()) cout << "-1";
    else cout << pq.top();

    return 0;
}
