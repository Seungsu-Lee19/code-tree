#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

#define MAX_N 50000

int n, q;

int a[MAX_N + 1];

// 각 숫자가 몇번째 인덱스인지 알아보기 위해 map을 이용합니다.
map<int, int> m;

int main() {
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    
    sort(a + 1, a + n + 1);
    // 정렬해서 각 숫자가 몇번째로 작은 숫자인지 기록합니다.
    for(int i = 1; i <= n; i++)
        m[a[i]] = i;
    
    while(q--) {
        int x;
        cin >> x;
        // 해당 숫자가 a배열에 있다면 계산을 진행합니다.
        if(m[x]) {
            int cur = m[x];
            // x는 cur번째로 작은 숫자입니다.
            // 이 숫자가 중앙값이 되려면 x보다 작은 (cur - 1)개의 숫자 중 하나와
            // x보다 큰 (n - cur)개의 숫자 중 하나를 골라야 합니다.
            cout << (cur - 1) * (n - cur);
            cout << "\n";
        }
        // 없다면 0을 출력합니다.
        else {
            cout << 0;
            cout << "\n";
        }
    }
    
    return 0;
}
