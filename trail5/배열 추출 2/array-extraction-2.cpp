#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <functional>

using namespace std;

int n;

int main() {
    cin >> n;

    int x;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < n; i++) {
        cin >> x;

        if(x != 0) pq.push({abs(x), x});
        else{
            if(pq.empty()) cout << "0\n";
            else{
                auto [a, b] = pq.top();
                cout << b << endl;
                pq.pop();
            }
        }
    }

    // Please write your code here.

    return 0;
}
