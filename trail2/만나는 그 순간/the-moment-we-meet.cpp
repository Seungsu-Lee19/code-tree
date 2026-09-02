#include <iostream>

using namespace std;

int n, m;
char d[1000];
int t[1000];
char d2[1000];
int t2[1000];

int main() {
    cin >> n >> m;

    int time = 1;

    for (int i = 0; i < n; i++) cin >> d[i] >> t[i];

    for (int i = 0; i < m; i++) {
        cin >> d2[i] >> t2[i];
        time += t2[i];
    }

    // Please write your code here.
    
    int dist[time] = {0, };
    int dist2[time] = {0, };

    int cur_time = 1;
    int cur = 0;
    for(int i = 0; i < n; i++){
        for(int j = cur_time; j < t[i] + cur_time; j++){
            if(d[i] == 'R'){
                dist[j] = cur + 1;
                cur++;
            }
            else{
                dist[j] = cur - 1;
                cur--;
            }
        }
        cur_time += t[i];
    }

    
    cur_time = 1;
    cur = 0;
    for(int i = 0; i < m; i++){
        for(int j = cur_time; j < t2[i] + cur_time; j++){
            if(d2[i] == 'R'){
                dist2[j] = cur + 1;
                cur++;
            }
            else{
                dist2[j] = cur - 1;
                cur--;
            }
        }
        cur_time += t2[i];
    }

    int ans = -1;
    for(int i = 1; i < time; i++){
        if(dist[i] == dist2[i]){
            ans = i;
            break;
        }
    }

    cout << ans;
    


    return 0;
}