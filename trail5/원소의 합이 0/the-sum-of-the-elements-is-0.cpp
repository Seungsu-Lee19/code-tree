#include <iostream>
#include <unordered_map>

using namespace std;

int n;
long long A[5000], B[5000], C[5000], D[5000];

int main() {
    cin >> n;

    for(int i = 0; i < n; i++) cin >> A[i];
    for(int i = 0; i < n; i++) cin >> B[i];
    for(int i = 0; i < n; i++) cin >> C[i];
    for(int i = 0; i < n; i++) cin >> D[i];

    unordered_map<long long, long long> mp;

    // A + B의 합이 각각 몇 번 나오는지 저장
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            long long sum = A[i] + B[j];
            mp[sum]++;
        }
    }

    long long ans = 0;

    // C + D와 합쳐서 0이 되는 A+B를 찾음
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            long long target = -(C[i] + D[j]);

            auto it = mp.find(target);

            if(it != mp.end()){
                ans += it->second;
            }
        }
    }

    cout << ans;

    return 0;
}