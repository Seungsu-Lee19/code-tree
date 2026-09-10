#include <iostream>
#include <deque>
#include <utility>

using namespace std;

int N, M, K;
int x, y;
char d[1000];
int p[1000];

int grid[101][101] = {0, };
deque<pair<int, int>> dq;

int main() {
    cin >> N >> M >> K;

    for (int i = 0; i < M; i++) {
        cin >> x >> y;

        grid[x][y] = 1;
    }

    for (int i = 0; i < K; i++) {
        cin >> d[i] >> p[i];
    }

    int time = 0;
    x = 1;
    y = 1;
    for(int i = 0; i < K; i++){
        bool isCanMove = true;
        for(int t = 0; t < p[i]; t++){
            int nx = x;
            int ny = y;

            time++;

            if(d[i] == 'L') ny--;
            else if(d[i] == 'R') ny++;
            else if(d[i] == 'U') nx--;
            else nx++;

            // 격자 벗어났을 떄
            if(nx < 1 || ny < 1 || nx > N || ny > N){
                isCanMove = false;
                break;
            }

            // 몸통 만났을 떄 not 꼬리-
            for(int k = 1; k < dq.size(); k++){
                if(dq[k].first == nx && dq[k].second == ny){
                    isCanMove = false;
                    break;
                }
            }
            if(isCanMove == false) break;

            // 사과 먹었을 떄
            dq.push_back({x, y});
            if(grid[nx][ny] == 1){
                grid[nx][ny] = 0;
            }
            else{
                // 꼬리 삭제
                if(!dq.empty()) dq.pop_front();
            }
            
            x = nx;
            y = ny;
        }   

        if(isCanMove == false) break;
    }
    cout << time;

    return 0;
}
