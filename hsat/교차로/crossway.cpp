#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <climits>

using namespace std;

int N;

int main() {
    cin >> N;

    queue<pair<int, int>> q[4];

    int t, cur = -1;
    char w;

    for (int i = 0; i < N; i++) {
        cin >> t >> w;
        
        if(cur == -1) cur = t;

        q[w - 'A'].push({t, i});
    }

    vector<int> ans(N, -1);

    while(!q[0].empty() || !q[1].empty() || !q[2].empty() || !q[3].empty()){
        vector<int> time(4, -1);
        vector<int> idx(4, -1);

        int min_time = INT_MAX;
        for(int i = 0; i < 4; i++){
            if(!q[i].empty()){
                auto [_t, _idx] = q[i].front();

                if(_t > cur) {
                    min_time = min(min_time, _t);
                    continue;
                }

                time[i] = _t;
                idx[i] = _idx;
            }
        }

        int isCanMove = 0;
        for(int i = 0; i < 4; i++){
            if(time[i] != -1) isCanMove++;
        }

        if(isCanMove == 4) break;
        if(isCanMove == 0){
            cur = min_time;
            continue;
        }

        for(int i = 0; i < 4; i++){
            // cout << time[i] << " " << time[(i + 3) % 4] << endl;
            if(time[i] != -1 && time[(i + 3) % 4] == -1){
                q[i].pop();
                ans[idx[i]] = time[i] + cur - time[i];
            }
        }

        cur++;
    }

    for(int i = 0; i < N; i++){
        cout << ans[i] << "\n";
    }

    return 0;
}
