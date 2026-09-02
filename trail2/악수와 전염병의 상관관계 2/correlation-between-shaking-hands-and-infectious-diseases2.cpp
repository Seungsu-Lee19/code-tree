#include <iostream>
#include <tuple>
#include <algorithm>

using namespace std;

int N, K, P, T;
int t;
int x;
int y;

int main() {
    cin >> N >> K >> P >> T;

    tuple<int, int, int> virus[T] = {};
    
    for (int i = 0; i < T; i++) {
        cin >> t >> x >> y;
        virus[i] = make_tuple(t, x, y);
    }

    // Please write your code here.
    sort(virus, virus + T);
    int people[N + 1];
    fill(people, people + (N + 1), -1);
    people[P] = K;
    
    for(int i = 0; i < T; i++){
        tie(t, x, y) = virus[i];
        if(people[x] > 0){
            people[x]--;
            if(people[y] > 0) people[y]--;
            else if(people[y] == -1) people[y] = K;
        }
        else if(people[y] > 0){
            people[y]--;
            if(people[x] > 0) people[x]--;
            else if(people[x] == -1) people[x] = K;
        }
    }

    for(int i = 1; i <= N; i++){
        if(people[i] >= 0) cout << 1;
        else cout << 0;
    }

    return 0;
}