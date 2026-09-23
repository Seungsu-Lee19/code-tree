#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int main() {
    cin >> n;

    vector<pair<int, int>> v;

    for(int i = 0; i < n; i++) {
        int x1, x2;
        cin >> x1 >> x2;

        // {끝점, 시작점}
        v.push_back({x2, x1});
    }

    // 끝점 기준 오름차순 정렬
    sort(v.begin(), v.end());

    int cnt = 0;
    int lastEnd = -1;

    for(auto [end, start] : v) {

        // 이전 구간과 겹치지 않는다면 선택
        if(start > lastEnd) {
            cnt++;
            lastEnd = end;
        }
    }

    cout << cnt;

    return 0;
}