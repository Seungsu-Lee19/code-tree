#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#include <functional>

using namespace std;

int n, m, k;
int arr1[100000];
int arr2[100000];

int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }

    // 각각 오름차순 정렬
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);

    // (합, arr1의 index, arr2의 index)
    priority_queue<
        tuple<long long, int, int>,
        vector<tuple<long long, int, int>>,
        greater<tuple<long long, int, int>>
    > pq;

    // 각 줄의 첫 번째 값만 넣기
    // arr1[i] + arr2[0]
    for (int i = 0; i < n; i++) {
        long long sum = (long long)arr1[i] + arr2[0];
        pq.push({sum, i, 0});
    }

    long long ans = 0;

    // 작은 합부터 K번 꺼내기
    for (int cnt = 0; cnt < k; cnt++) {
        auto [sum, i, j] = pq.top();
        pq.pop();

        ans = sum;

        // 같은 줄의 다음 값 넣기
        // arr1[i] + arr2[j + 1]
        if (j + 1 < m) {
            long long nextSum =
                (long long)arr1[i] + arr2[j + 1];

            pq.push({nextSum, i, j + 1});
        }
    }

    cout << ans;

    return 0;
}