#include <iostream>
#include <queue>

using namespace std;

int n;
long long arr;

int main() {
    cin >> n;

    priority_queue<long long> pq;

    for (int i = 0; i < n; i++) {
        cin >> arr;
        pq.push(-arr);

        if(i < 2) {
            cout << "-1\n";
            continue;
        }

        vector<long long> v;
        v.push_back(-pq.top());
        pq.pop();
        v.push_back(-pq.top());
        pq.pop();
        v.push_back(-pq.top());
        pq.pop();

        long long ans = 1;
        for(int i = 0; i < 3; i++){
            pq.push(-v[i]);
            ans = ans * v[i];
        }
        cout << ans << endl;
    }

    // Please write your code here.

    return 0;
}
