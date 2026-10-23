#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<long long> positions;

bool check(int mid){
    int patch = mid;

    int s = positions[0];
    int f = s + mid - 1;

    int k = 1;

    for(int i = 1; i < N; i++){
        // cout << s << " " << f << " " << k << " " << mid << endl;
        if(positions[i] > f){
            // s = positions[i] - (positions[i] - f);
            s = positions[i];
            f = s + mid - 1;
            k++;
        }
    }
    // cout << endl;

    if(k <= K) return true;
    return false;
}

int main() {
    cin >> N >> K;

    positions.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> positions[i];
    }

    // Please write your code here.
    int left = 1;
    int right = positions[N - 1];
    int ans = right - left + 1;

    while(left <= right){
        int mid = (left + right) / 2;

        if(check(mid)){
            right = mid - 1;
            ans = mid;
        }
        else{
            left = mid + 1;
        }
    }

    cout << ans;

    return 0;
}
