#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int H, K, R;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> H >> K >> R;

    vector<queue<int>> tasks((1 << (H + 1)));

    vector<vector<queue<int>>> work((1 << (H + 1)), vector<queue<int>> (2));

    for (int i = (1 << H); i < (1 << (H + 1)); i++) {
        for (int j = 0; j < K; j++) {
            int task;
            cin >> task;
            tasks[i].push(task);
        }
    }

    int ans = 0;
    int day = 1;

    while(day <= R){
        for(int i = 1; i < (1 << H); i++){
            if(!work[i][day % 2].empty()){
                int task = work[i][day % 2].front();
                work[i][day % 2].pop();

                if(i == 1) ans += task;
                else{
                    work[i / 2][(i + 1) % 2].push(task);
                }
            }
        }

        for (int i = (1 << H); i < (1 << (H + 1)); i++) {
            if(!tasks[i].empty()){
                int task = tasks[i].front();
                tasks[i].pop();

                work[i / 2][(i + 1) % 2].push(task);
            }
        }

        day++;
    }

    cout << ans;

    // Please write your code here.

    return 0;
}
