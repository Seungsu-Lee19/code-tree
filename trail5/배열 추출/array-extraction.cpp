#include <iostream>
#include <queue>

using namespace std;

int n;

int main() {
    cin >> n;

    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if(x > 0) pq.push(x);
        else{
            if(pq.empty()) {
                cout << "0\n";
                continue;
            }
            
            cout << pq.top() << endl;
            pq.pop();
        }
    }

    // Please write your code here.

    return 0;
}
