#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// food : 집마다 (실제 식량 비축량 - 지금까지 받은 영지 강화의 합)을 오름차순으로 저장합니다.
// 영지 강화는 그때 있는 모든 집을 똑같이 늘리므로, 이렇게 저장한 값의 순서는 영지 강화로 바뀌지 않습니다.
vector<long long> food;

// prefix[k] : food[0] + food[1] + ... + food[k - 1]입니다.
vector<long long> prefix;

// upgradeSum : 지금까지 받은 영지 강화의 합입니다. 실제 식량 비축량은 food[i] + upgradeSum입니다.
long long upgradeSum = 0;

// food[from]부터 값이 바뀌었을 때 prefix[from + 1]부터 다시 계산합니다.
// prefix[from]까지는 바뀐 값이 들어 있지 않으므로 그대로 둡니다.
void rebuildPrefix(int from) {
    prefix.resize(food.size() + 1);
    for (int i = from; i < (int)food.size(); i++)
        prefix[i + 1] = prefix[i] + food[i];
}

// 비축량이 적은 순으로 k개 집을 k번째로 적은 집의 비축량까지 채우는 데 필요한 식량입니다.
// 모든 저장값이 실제 비축량보다 upgradeSum만큼 작으므로, 저장값으로 계산해도 결과가 같습니다.
long long cost(int k) {
    return (long long)k * food[k - 1] - prefix[k];
}

// 식량 p를 보급할 때 가장 적은 식량 비축량이 될 수 있는 최댓값을 구합니다.
long long winter(long long p) {
    // cost(k)는 k가 커질수록 커지므로, cost(k) <= p인 가장 큰 k를 이분 탐색으로 찾습니다.
    // cost(1) = 0이므로 k는 항상 1 이상입니다.
    int lo = 1, hi = food.size();
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        if (cost(mid) <= p) lo = mid;
        else hi = mid - 1;
    }
    long long k = lo;

    // 비축량이 적은 k개 집의 실제 비축량 합에 p를 더해 k개 집에 고르게 나눈 몫이 답입니다.
    // 저장값은 음수일 수 있으므로, 실제 비축량의 합(항상 양수)으로 나눗셈을 합니다.
    long long realSum = prefix[k] + k * upgradeSum;
    return (realSum + p) / k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    string out;
    while (q--) {
        int type;
        cin >> type;
        if (type == 100) {
            // 게임 시작: 처음 집들은 아직 영지 강화를 받지 않았으므로 비축량을 그대로 저장합니다.
            int n;
            cin >> n;
            food.resize(n);
            for (int i = 0; i < n; i++) cin >> food[i];
            sort(food.begin(), food.end());
            prefix.assign(1, 0);
            rebuildPrefix(0);
        } else if (type == 200) {
            // 이주: 이전 영지 강화를 받지 않으므로 지금까지의 영지 강화의 합을 빼서 저장합니다.
            long long x;
            cin >> x;
            long long value = x - upgradeSum;
            int pos = upper_bound(food.begin(), food.end(), value) - food.begin();
            food.insert(food.begin() + pos, value);
            rebuildPrefix(pos);
        } else if (type == 300) {
            // 영지 강화: 영지 강화의 합만 늘립니다.
            long long p;
            cin >> p;
            upgradeSum += p;
        } else {
            // 겨울나기: 보급한 식량은 겨울이 지나면 회수되므로 저장한 값은 바꾸지 않습니다.
            long long p;
            cin >> p;
            out += to_string(winter(p)) + '\n';
        }
    }
    cout << out;
    return 0;
}

