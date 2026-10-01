#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int n, m;

int main() {
    cin >> n >> m;

    priority_queue<tuple<int, int, int>> pq;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        pq.push({-(x + y), -x, -y});
    }

    // Please write your code here.
    for(int i = 0; i < m; i++){
        auto [d, x, y] = pq.top();
        pq.pop();

        x = -x + 2;
        y = -y + 2;
        pq.push({-(x + y), -x, -y});
    }

    auto [d, x, y] = pq.top();
    cout << -x << " " << -y;

    return 0;
}
