#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <tuple>

using namespace std;

int T, N, M, K;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void bfs(int sx, int sy, vector<vector<bool>>& visited, vector<vector<int>>& wave){
    queue<pair<int, int>> q;
    q.push({sx, sy});

    vector<pair<int, int>> new_mud;
    new_mud.push_back({sx, sy});

    int cnt = 1;
    int su = wave[sx][sy];

    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

            if(!visited[nx][ny] && wave[nx][ny] > 0){
                q.push({nx, ny});
                visited[nx][ny] = true;

                new_mud.push_back({nx, ny});

                cnt++;
                su += wave[nx][ny];
            }
        }
    }

    int v = su / cnt;
    for(int i = 0; i < new_mud.size(); i++){
        auto [x, y] = new_mud[i];
        wave[x][y] = v;
    }
    
}

int main() {
    cin >> T;
    // Please write your code here.
    for(int t = 0; t < T; t++){
        cin >> N >> M >> K;

        vector<vector<int>> mud(N, vector<int>(M));
        priority_queue<tuple<int, int, int, int, int, int>> cannon;
        priority_queue<tuple<int, int, int, int>> stone;

        for(int k = 0; k < K; k++){
            int c, s, d, a, h, p;
            // 투석기가 놓인 열, 발사 시작 시각, 발사 간격, 돌의 무게, 날아가는 거리, 돌의 수

            cin >> c >> s >> d >> a >> h >> p;
            cannon.push({-s, c, d, a, h, p});
        }


        cout << "#" << t + 1 << " ";

        for(int time = 1; time <= 50; time++){
            if(cannon.empty() && stone.empty()) break;

            while(!cannon.empty()){ // 2단계
                auto [s, c, d, a, h, p] = cannon.top();
                s = -s;

                if(time == s){
                    // 발사
                    cannon.pop();

                    stone.push({-(s + h - 1), N - h, c, a});

                    if(p - 1 > 0){
                        cannon.push({-(s + d), c, d, a, h, p - 1});
                    }
                }
                else break;
            }

            bool isDrop = false;
            int mud_sum = 0;
            vector<vector<int>> wave(N, vector<int>(M));
            while(!stone.empty()){ // 3단계
                auto [s, r, c, a] = stone.top();
                s = -s;

                if(s == time){
                    // 물에 퐁당
                    stone.pop();
                    // wave[r][c] += 3 * a;

                    for(int i = 0; i < N; i++){
                        for(int j = 0; j < M; j++){
                            int v = max(0, 3 * a - 5 * (abs(i - r) + abs(j - c)));
                            wave[i][j] += v;
                        }
                    }
                    isDrop = true;
                }
                else break;
            }

            // 4단계 점수 계산
            int score = 0;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    score += max(0, wave[i][j] - mud[i][j]);
                }
            }
            cout << max(0, score) << " ";

            // 5단계
            vector<vector<int>> mud_temp(N, vector<int>(M));
            for(int i = 0; i < N; i++){
                for(int j = 0; j < M; j++){
                    if(mud[i][j] > 0){
                        int cnt = 0;
                        mud_temp[i][j] = mud[i][j] - 2;
                        for(int k = 0; k < 4; k++){
                            int nx = i + dx[k];
                            int ny = j + dy[k];

                            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

                            if(mud[nx][ny] > 0) cnt++;
                        }

                        if(cnt == 4) mud_temp[i][j]++;

                        mud_temp[i][j] = max(0, mud_temp[i][j]);
                    }
                }
            }
            mud = mud_temp;

            // 6단계
            for(int i = 0; i < N; i++){
                for(int j = 1; j < M; j++){
                    mud[i][j - 1] = mud[i][j];
                }
                mud[i][M - 1] = 0;
            }

            // 7단계
            if(isDrop){
                vector<vector<bool>> visit(N, vector<bool>(M));
                for(int i = 0; i < N; i++){
                    for(int j = 0; j < M; j++){
                        if(wave[i][j] > 0 && !visit[i][j]){
                            visit[i][j] = true;
                            bfs(i, j, visit, wave);
                        }
                    }
                }

                for(int i = 0; i < N; i++){
                    for(int j = 0; j < M; j++){
                        if(wave[i][j] > 0) mud[i][j] += wave[i][j];
                    }
                }
            }
        }

        cout << "\n";
    }
    return 0;
}