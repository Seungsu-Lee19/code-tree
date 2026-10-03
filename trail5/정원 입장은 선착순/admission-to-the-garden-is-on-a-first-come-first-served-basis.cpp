#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <functional>

using namespace std;

int N;

int main() {
    cin >> N;
    
    long long a;
    long long t;
    vector<tuple<long long, long long, int>> ve;
    for (int i = 0; i < N; i++) {
        cin >> a >> t;
        ve.push_back({a, t, i + 1});
    }

    sort(ve.begin(), ve.end());

    priority_queue<
        tuple<int, long long, long long>,
        vector<tuple<int, long long, long long>>,
        greater<tuple<int, long long, long long>>
    > pq;

    long long ans = 0;
    long long cur = 0;
    int i = 0;

    while(i < N || !pq.empty()){
        if(pq.empty()){
            auto [start, end, idx] = ve[i];
            if(cur < start) cur = start;
        }

        while(i < N){
            auto [start, end, idx] = ve[i];
            
            if(cur < start) break;

            pq.push({idx, start, end});
            i++;
        }

        auto [idx, start, end] = pq.top();
        pq.pop();

        ans = max(ans, cur - start);

        cur += end;
    }

    cout << ans;

    return 0;
}
