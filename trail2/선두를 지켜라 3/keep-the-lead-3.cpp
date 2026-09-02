#include <iostream>

using namespace std;

int N, M;
int v, t;

int main() {
    cin >> N >> M;

    int pos_a[1000001] = {0, };
    int cur_pos = 0;
    int cur_time = 1;
    for (int i = 0; i < N; i++) {
        cin >> v >> t;

        for(int j = cur_time; j < cur_time + t; j++){
            cur_pos += v;
            pos_a[j] = cur_pos;
        }

        cur_time += t;
    }

    int pos_b[1000001] = {0, };
    cur_pos = 0;
    cur_time = 1;
    for (int i = 0; i < M; i++) {
        cin >> v >> t;

        for(int j = cur_time; j < cur_time + t; j++){
            cur_pos += v;
            pos_b[j] = cur_pos;
        }

        cur_time += t;
    }

    int ans = 0;
    int win = 0;

    for(int i = 1; i < cur_time; i++){
        if(pos_a[i] > pos_b[i]){
            if(win != 1){
                win = 1;
                ans++;
                // cout << ans << " " << win << " " << i << endl;
            }
        }
        else if(pos_a[i] < pos_b[i]){
            if(win != 2){
                win = 2;
                ans++;
                // cout << ans << " " << win << " " << i << endl;
            }
        }
        else{
            if(win != 3){
                win = 3;
                ans++;
                // cout << ans << " " << win << " " << i << endl;
            }    
        }
    }
    cout << ans;

    return 0;
}