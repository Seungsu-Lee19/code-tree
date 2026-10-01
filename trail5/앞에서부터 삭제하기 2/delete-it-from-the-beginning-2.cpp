#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iomanip>

using namespace std;

int N;

int main() {
    cin >> N;

    vector<int> arr(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    priority_queue<int> pq;

    long long sum = 0;
    double ans = 0;

    // 뒤에서부터 하나씩 추가
    for (int i = N - 1; i >= 1; i--) {
        pq.push(-arr[i]);
        sum += arr[i];

        // 최소값을 제외하고도 원소가 하나 이상 있어야 함
        if (pq.size() >= 2) {
            long long minValue = -pq.top();

            double avg =
                (double)(sum - minValue) / (pq.size() - 1);

            ans = max(ans, avg);
        }
    }

    cout << fixed << setprecision(2) << ans;

    return 0;
}