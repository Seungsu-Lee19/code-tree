#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int t;
char d;

int main() {
    cin >> n >> m;

    int pos_a[2000001] = {0, };
    int cur_time_a = 1;
    int pos = 0;
    for (int i = 0; i < n; i++) {
        cin >> t >> d;

        for(int _t = cur_time_a; _t < t + cur_time_a; _t++){
            if(d == 'L') pos--;
            else pos++;
            
            pos_a[_t] = pos;
        }
        cur_time_a += t;
    }
    cur_time_a--;

    int pos_b[2000001] = {0, };
    int cur_time_b = 1;
    pos = 0;
    for (int i = 0; i < m; i++) {
        cin >> t >> d;

        for(int _t = cur_time_b; _t < t + cur_time_b; _t++){
            if(d == 'L') pos--;
            else pos++;
            
            pos_b[_t] = pos;
        }
        cur_time_b += t;
    }
    cur_time_b--;

    int ans = 0;

    for(int i = 2; i <= min(cur_time_a, cur_time_b); i++){
        if(pos_a[i] == pos_b[i] && pos_a[i - 1] != pos_b[i - 1]){
            ans++;

            // cout << i << " ? " << endl;
        }
    }

    if(cur_time_a > cur_time_b){
        for(int i = cur_time_b + 1; i <= cur_time_a; i++){
            if(pos_a[i] == pos_b[cur_time_b]){
                ans++;
                // cout << i << endl;
            }
        }
    }
    else if(cur_time_a < cur_time_b){
        for(int i = cur_time_a + 1; i <= cur_time_b; i++){
            if(pos_a[cur_time_a] == pos_b[i]){
                ans++;
                // cout << i << endl;
            }
        }
    }

    cout << ans;
    // Please write your code here.

    return 0;
}