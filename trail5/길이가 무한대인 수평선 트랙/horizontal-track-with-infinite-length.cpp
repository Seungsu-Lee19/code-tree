#include <iostream>
#include <set>

using namespace std;

int N, T;
long long start;
long long speed;

int main() {
    cin >> N >> T;

    set<long long> se;
    for (int i = 0; i < N; i++) {
        cin >> start >> speed;

        long long dist = start + (long long)speed * T;

        auto it = se.lower_bound(dist);

        if(it != se.end()){
            se.erase(it, se.end());
        }

        se.insert(dist);

        // for(long long l : se){
        //     cout << l << " ";
        // }
        // cout << endl;
    }

    cout << se.size();

    // Please write your code here.
    // 각자 다른 위치에서 동시에 출발
    // 각자 다른 속도로 T분동안 달림

    // start + speed * t == dist라 할 때
    // i의 dist보다 (i - 1) 이하의 dist가 크거나 같으면
    // i의 dist는 (i - 1) 이하의 dist가 됨.
    // start + speed * t => set() 넣음

    return 0;
}
