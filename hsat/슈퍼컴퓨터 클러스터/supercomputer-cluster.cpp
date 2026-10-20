#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

using ll = long long;

int N;
ll B;

priority_queue<ll> q;

bool check(ll mid){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll cost = B;
    priority_queue<ll> temp = q;

    while(!temp.empty()){
        ll a = -temp.top();
        temp.pop();

        if(a >= mid) return true;

        cost = cost - (a - mid) * (a - mid);

        if(cost < 0) return false;
    }

    return true;
}

int main() {
    cin >> N >> B;

    int a;
    for (int i = 0; i < N; i++) {
        cin >> a;
        q.push(-a);
    }

    // 성능이 가장 낮은 컴퓨터의 성능을 최대화. 단, B원 이하의 비용으로
    ll left = -q.top();
    ll right = left + (ll)sqrtl(B);

    ll ans;

    while(left <= right){
        ll mid = (left + right) / 2;
        // cout << left << " " << right << " => " << endl;

        bool c = check(mid);


        if(c){
            left = mid + 1;
            ans = mid;
        }
        else{
            right = mid - 1;
        }
    }

    cout << ans;

    return 0;
}
