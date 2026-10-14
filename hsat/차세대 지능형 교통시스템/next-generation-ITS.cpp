#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <set>
#include <tuple>

using namespace std;

int N, T;
vector<vector<vector<int>>> signals;

void bfs(int sx, int sy){
    queue<tuple<int, int, int, int>> q;
    vector<vector<vector<vector<bool>>>> visited(
        N,
        vector<vector<vector<bool>>> (
            N,
            vector<vector<bool>>(
                4,
                vector<bool> (4)
            )
        )
    ); 
    // [x][y][t][dir]
    // dir : 0 오른쪽, 1이면 위, 2면 왼쪽, 3이면 아래

    set<pair<int, int>> se;

    visited[sx][sy][0][1] = true;
    q.push({sx, sy, 0, 1});
    se.insert({sx, sy});

    while(!q.empty()){
        auto [x, y, t, dir] = q.front();
        q.pop();

        // cout << x << " " << y << " : " << t << endl;

        if(t >= T) continue;

        int sig = signals[x][y][t % 4];

        int nx, ny;
        if(sig == 1 && dir == (sig - 1) % 4){
            nx = x;
            ny = y + 1;
            if(nx >= 0 && ny >= 0 && nx < N && ny < N){
                if(!visited[nx][ny][(t + 1) % 4][0]){
                    visited[nx][ny][(t + 1) % 4][0] = true;
                    se.insert({nx, ny});
                    q.push({nx, ny, t + 1, 0});
                }
            }
            
            nx = x + 1;
            ny = y;
            if(nx >= 0 && ny >= 0 && nx < N && ny < N){
                if(!visited[nx][ny][(t + 1) % 4][3]){
                    visited[nx][ny][(t + 1) % 4][3] = true;
                    se.insert({nx, ny});
                    q.push({nx, ny, t + 1,3});
                }
            }
            
            nx = x - 1;
            ny = y;
            if(nx >= 0 && ny >= 0 && nx < N && ny < N){
                if(!visited[nx][ny][(t + 1) % 4][1]){
                    visited[nx][ny][(t + 1) % 4][1] = true;
                    se.insert({nx, ny});
                    q.push({nx, ny, t + 1,1});
                }
            }
        }
        else if(sig == 2 && dir == (sig - 1) % 4){
            nx = x;
            ny = y - 1;
            if(nx >= 0 && ny >= 0 && nx < N && ny < N){
                if(!visited[nx][ny][(t + 1) % 4][2]){
                    visited[nx][ny][(t + 1) % 4][2] = true;
                    se.insert({nx, ny});
                    q.push({nx, ny, t + 1,2});
                }
            }
            
            nx = x - 1;
            ny = y;
            if(nx >= 0 && ny >= 0 && nx < N && ny < N){
                if(!visited[nx][ny][(t + 1) % 4][1]){
                    visited[nx][ny][(t + 1) % 4][1] = true;
                    se.insert({nx, ny});
                    q.push({nx, ny, t + 1,1});
                }
            }
            
            nx = x;
            ny = y + 1;
            if(nx >= 0 && ny >= 0 && nx < N && ny < N){
                if(!visited[nx][ny][(t + 1) % 4][0]){
                    visited[nx][ny][(t + 1) % 4][0] = true;
                    se.insert({nx, ny});
                    q.push({nx, ny, t + 1,0});
                }
            }
        }
        else if(sig == 3 && dir == (sig - 1) % 4){
            nx = x;
            ny = y - 1;
            if(nx >= 0 && ny >= 0 && nx < N && ny < N){
                if(!visited[nx][ny][(t + 1) % 4][2]){
                    visited[nx][ny][(t + 1) % 4][2] = true;
                    se.insert({nx, ny});
                    q.push({nx, ny, t + 1,2});
                }
            }
            
            nx = x + 1;
            ny = y;
            if(nx >= 0 && ny >= 0 && nx < N && ny < N){
                if(!visited[nx][ny][(t + 1) % 4][3]){
                    visited[nx][ny][(t + 1) % 4][3] = true;
                    se.insert({nx, ny});
                    q.push({nx, ny, t + 1,3});
                }
            }
            
            nx = x - 1;
            ny = y;
            if(nx >= 0 && ny >= 0 && nx < N && ny < N){
                if(!visited[nx][ny][(t + 1) % 4][1]){
                    visited[nx][ny][(t + 1) % 4][1] = true;
                    se.insert({nx, ny});
                    q.push({nx, ny, t + 1,1});
                }
            }
        }
        else if(sig == 4 && dir == (sig - 1) % 4){
            nx = x;
            ny = y - 1;
            if(nx >= 0 && ny >= 0 && nx < N && ny < N){
                if(!visited[nx][ny][(t + 1) % 4][2]){
                    visited[nx][ny][(t + 1) % 4][2] = true;
                    se.insert({nx, ny});
                    q.push({nx, ny, t + 1,2});
                }
            }
            
            nx = x + 1;
            ny = y;
            if(nx >= 0 && ny >= 0 && nx < N && ny < N){
                if(!visited[nx][ny][(t + 1) % 4][3]){
                    visited[nx][ny][(t + 1) % 4][3] = true;
                    se.insert({nx, ny});
                    q.push({nx, ny, t + 1,3});
                }
            }
            
            nx = x;
            ny = y + 1;
            if(nx >= 0 && ny >= 0 && nx < N && ny < N){
                if(!visited[nx][ny][(t + 1) % 4][0]){
                    visited[nx][ny][(t + 1) % 4][0] = true;
                    se.insert({nx, ny});
                    q.push({nx, ny, t + 1,0});
                }
            }
        }
        else if(sig == 5 && dir == (sig - 1) % 4){
            nx = x;
            ny = y + 1;
            if(nx >= 0 && ny >= 0 && nx < N && ny < N){
                if(!visited[nx][ny][(t + 1) % 4][0]){
                    visited[nx][ny][(t + 1) % 4][0] = true;
                    se.insert({nx, ny});
                    q.push({nx, ny, t + 1,0});
                }
            }
            
            nx = x - 1;
            ny = y;
            if(nx >= 0 && ny >= 0 && nx < N && ny < N){
                if(!visited[nx][ny][(t + 1) % 4][1]){
                    visited[nx][ny][(t + 1) % 4][1] = true;
                    se.insert({nx, ny});
                    q.push({nx, ny, t + 1,1});
                }
            }
        }
        else if(sig == 6 && dir == (sig - 1) % 4){
            nx = x;
            ny = y - 1;
            if(nx >= 0 && ny >= 0 && nx < N && ny < N){
                if(!visited[nx][ny][(t + 1) % 4][2]){
                    visited[nx][ny][(t + 1) % 4][2] = true;
                    se.insert({nx, ny});
                    q.push({nx, ny, t + 1,2});
                }
            }
            
            nx = x - 1;
            ny = y;
            if(nx >= 0 && ny >= 0 && nx < N && ny < N){
                if(!visited[nx][ny][(t + 1) % 4][1]){
                    visited[nx][ny][(t + 1) % 4][1] = true;
                    se.insert({nx, ny});
                    q.push({nx, ny, t + 1,1});
                }
            }
        }
        else if(sig == 7 && dir == (sig - 1) % 4){
            nx = x;
            ny = y - 1;
            if(nx >= 0 && ny >= 0 && nx < N && ny < N){
                if(!visited[nx][ny][(t + 1) % 4][2]){
                    visited[nx][ny][(t + 1) % 4][2] = true;
                    se.insert({nx, ny});
                    q.push({nx, ny, t + 1,2});
                }
            }
            
            nx = x + 1;
            ny = y;
            if(nx >= 0 && ny >= 0 && nx < N && ny < N){
                if(!visited[nx][ny][(t + 1) % 4][3]){
                    visited[nx][ny][(t + 1) % 4][3] = true;
                    se.insert({nx, ny});
                    q.push({nx, ny, t + 1,3});
                }
            }
        }
        else if(sig == 8 && dir == (sig - 1) % 4){
            nx = x;
            ny = y + 1;
            if(nx >= 0 && ny >= 0 && nx < N && ny < N){
                if(!visited[nx][ny][(t + 1) % 4][0]){
                    visited[nx][ny][(t + 1) % 4][0] = true;
                    se.insert({nx, ny});
                    q.push({nx, ny, t + 1,0});
                }
            }
            
            nx = x + 1;
            ny = y;
            if(nx >= 0 && ny >= 0 && nx < N && ny < N){
                if(!visited[nx][ny][(t + 1) % 4][3]){
                    visited[nx][ny][(t + 1) % 4][3] = true;
                    se.insert({nx, ny});
                    q.push({nx, ny, t + 1,3});
                }
            }
        }
        else if(sig == 9 && dir == (sig - 1) % 4){
            nx = x;
            ny = y + 1;
            if(nx >= 0 && ny >= 0 && nx < N && ny < N){
                if(!visited[nx][ny][(t + 1) % 4][0]){
                    visited[nx][ny][(t + 1) % 4][0] = true;
                    se.insert({nx, ny});
                    q.push({nx, ny, t + 1,0});
                }
            }
            
            nx = x + 1;
            ny = y;
            if(nx >= 0 && ny >= 0 && nx < N && ny < N){
                if(!visited[nx][ny][(t + 1) % 4][3]){
                    visited[nx][ny][(t + 1) % 4][3] = true;
                    se.insert({nx, ny});
                    q.push({nx, ny, t + 1,3});
                }
            }
        }
        else if(sig == 10 && dir == (sig - 1) % 4){
            nx = x;
            ny = y + 1;
            if(nx >= 0 && ny >= 0 && nx < N && ny < N){
                if(!visited[nx][ny][(t + 1) % 4][0]){
                    visited[nx][ny][(t + 1) % 4][0] = true;
                    se.insert({nx, ny});
                    q.push({nx, ny, t + 1,0});
                }
            }
            
            nx = x - 1;
            ny = y;
            if(nx >= 0 && ny >= 0 && nx < N && ny < N){
                if(!visited[nx][ny][(t + 1) % 4][1]){
                    visited[nx][ny][(t + 1) % 4][1] = true;
                    se.insert({nx, ny});
                    q.push({nx, ny, t + 1,1});
                }
            }
        }
        else if(sig == 11 && dir == (sig - 1) % 4){
            nx = x;
            ny = y - 1;
            if(nx >= 0 && ny >= 0 && nx < N && ny < N){
                if(!visited[nx][ny][(t + 1) % 4][2]){
                    visited[nx][ny][(t + 1) % 4][2] = true;
                    se.insert({nx, ny});
                    q.push({nx, ny, t + 1,2});
                }
            }
            
            nx = x - 1;
            ny = y;
            if(nx >= 0 && ny >= 0 && nx < N && ny < N){
                if(!visited[nx][ny][(t + 1) % 4][1]){
                    visited[nx][ny][(t + 1) % 4][1] = true;
                    se.insert({nx, ny});
                    q.push({nx, ny, t + 1,1});
                }
            }
        }
        else if(sig == 12 && dir == (sig - 1) % 4){
            nx = x;
            ny = y - 1;
            if(nx >= 0 && ny >= 0 && nx < N && ny < N){
                if(!visited[nx][ny][(t + 1) % 4][2]){
                    visited[nx][ny][(t + 1) % 4][2] = true;
                    se.insert({nx, ny});
                    q.push({nx, ny, t + 1,2});
                }
            }
            
            nx = x + 1;
            ny = y;
            if(nx >= 0 && ny >= 0 && nx < N && ny < N){
                if(!visited[nx][ny][(t + 1) % 4][3]){
                    visited[nx][ny][(t + 1) % 4][3] = true;
                    se.insert({nx, ny});
                    q.push({nx, ny, t + 1,3});
                }
            }
        }
    }

    // cout << endl;
    // for(auto [x, y] : se){
    //     cout << x << " " << y << endl;
    // }

    cout << se.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> T;
    signals.resize(N, vector<vector<int>>(N, vector<int>(4)));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < 4; k++) {
                cin >> signals[i][j][k];
            }
        }
    }

    bfs(0, 0);

    return 0;
}
