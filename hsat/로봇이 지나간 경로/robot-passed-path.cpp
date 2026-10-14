#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <climits>
#include <utility>
#include <queue>

using namespace std;

int H, W;

vector<vector<char>> grid;
vector<char> command;

int cmd_cnt = INT_MAX;
int start_dir = 0;
pair<int, int> start = {0, 0};

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(int sx, int sy, int d){
    int cnt = 0;
    for(int i = 0; i < 4; i++){
        int nx = sx + dx[i];
        int ny = sy + dy[i];
        
        if(nx < 0 || ny < 0 || nx >= H || ny >= W) {
            cnt++;
            continue;
        }

        if(grid[nx][ny] == '.') cnt++;
    }

    if(cnt != 3) return;

    queue<tuple<int, int, int>> q;
    vector<vector<char>> visited(H, vector<char> (W, '.'));

    q.push({sx, sy, d});
    visited[sx][sy] = '#';

    vector<char> cmd;

    while(!q.empty()){
        auto [x, y, dir] = q.front();
        q.pop();

        // if(sx == 8 && sy == 13){
        //     cout << x << " " << y << " : " << dir << endl;
        // }

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            int nx2 = x + dx[i] * 2;
            int ny2 = y + dy[i] * 2;

            if(nx < 0 || ny < 0 || nx >= H || ny >= W) continue;
            if(nx2 < 0 || ny2 < 0 || nx2 >= H || ny2 >= W) continue;
            if(grid[nx][ny] == '.' || grid[nx2][ny2] == '.') continue;
            if(visited[nx][ny] != '.' || visited[nx2][ny2] != '.') continue;

            visited[nx][ny] = '#';
            visited[nx2][ny2] = '#';

            int cw = (i - dir + 4) % 4;
            int ccw = (dir - i + 4) % 4;
        
            q.push({nx2, ny2, i});

            if(i == dir){
                cmd.push_back('A');
            }
            else if(cw < ccw){
                cmd.push_back('R');
                cmd.push_back('A');
            }
            else if(cw > ccw){
                cmd.push_back('L');
                cmd.push_back('A');
            }
            else{
                cmd.push_back('L');
                cmd.push_back('L');
                cmd.push_back('A');
            }
        }
    }
    
    if(visited != grid) return;

    if((int)cmd.size() <= cmd_cnt && make_pair(sx, sy) >= start){
        command = cmd;
        cmd_cnt = (int)cmd.size();
        start = {sx, sy};
        start_dir = d;
    }
}

int main() {
    cin >> H >> W;

    grid.resize(H, vector<char>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if(grid[i][j] == '#') {
                for(int k = 0; k < 4; k++){
                    bfs(i, j, k);
                }
            }
        }
    }

    cout << start.first + 1 << " " << start.second + 1 << "\n";
    if(start_dir == 0) cout << "^\n";
    else if(start_dir == 1) cout << ">\n";
    else if(start_dir == 2) cout << "v\n";
    else if(start_dir == 3) cout << "<\n";
    for(char cmd: command) cout << cmd;

    return 0;
}
