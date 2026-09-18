#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k;
int nums[12];
vector<int> horse;
int ans = 0;

void check(){
    int cnt = 0;
    for(int i = 0; i < k; i++){
        if(horse[i] >= m) cnt++;
        // cout << horse[i] << " ";
    }
    // cout << endl;

    ans = max(ans, cnt);
}


void back(int cnt){
    if(cnt == n){
        check();
        return;
    }

    for(int i = 0; i < k; i++){
        horse[i] += nums[cnt];
        back(cnt + 1);
        horse[i] -= nums[cnt];
    }
}

int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Please write your code here.
    horse.resize(k, 1);
    back(0);
    cout << ans;

    return 0;
}
