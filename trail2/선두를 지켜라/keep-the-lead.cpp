#include <iostream>

using namespace std;

int N, M;
int v[1000], t[1000];
int v2[1000], t2[1000];

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) cin >> v[i] >> t[i];

    for (int i = 0; i < M; i++) cin >> v2[i] >> t2[i];

    // Please write your code here.
    
    int dist[1000001] = {0, };
    int dist2[1000001] = {0, };

    int cur = 1;
    int _v = 0;
    
    for(int i = 0; i < N; i++){
        for(int j = cur; j < t[i] + cur; j++){
            _v += v[i];
            dist[j] = _v;
        }
        cur += t[i];
    }

    cur = 1;
    _v = 0;
    for(int i = 0; i < M; i++){
        for(int j = cur; j < t2[i] + cur; j++){
            _v += v2[i];
            dist2[j] = _v;
        }
        cur += t2[i];
    }

    int cnt = 0;
    int first = 0;
    for(int i = 1; i < 1000001; i++){
        if(first == 0){
            if(dist[i] == dist2[i]) continue;
            else if(dist[i] > dist2[i]) first = 1;
            else first = 2;
        }
        else if(first == 1){
            if(dist[i] < dist2[i]){
                first = 2;
                cnt++;
            }
        }
        else{
            if(dist[i] > dist2[i]){
                first = 1;
                cnt++;
            }
        }
    }

    cout << cnt;


    return 0;
}