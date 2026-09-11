#include <iostream>
#include <utility>
#include <tuple>
#include <map>

using namespace std;

using Ball = tuple<int, int, int, int, int>;
                // idx, weight, x, y, dir

using BallMap = map<pair<int, int>, Ball>;

BallMap balls;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

int n, m, t;

tuple<int, int, int> move(int idx, int w, int x, int y, int dir){
    int nx = x + dx[dir];
    int ny = y + dy[dir];

    if(nx < 1 || ny < 1 || nx > n || ny > n) {
        dir = (dir + 2) % 4;

        return {x, y, dir};
    }

    return {nx, ny, dir};
}

void move_all(){
    BallMap next;

    for(auto [pos, ball]: balls){
        auto [idx, w, x, y, dir] = ball;

        auto [nx, ny, n_dir] = move(idx, w, x, y, dir);

        pair<int, int> next_pos = {nx, ny};
        Ball next_ball = {idx, w, nx, ny, n_dir};
        
        if(next.find(next_pos) == next.end()){
            next[next_pos] = next_ball;
        }
        else{
            auto [prev_idx, prev_w, prev_x, prev_y, prev_dir] = next[next_pos];
            if(next[next_pos] < next_ball){
                next[next_pos] = {idx, prev_w + w, nx, ny, n_dir};
            }
            else{
                next[next_pos] = {prev_idx, prev_w + w, prev_x, prev_y, prev_dir};
            }
        }
    }

    balls = next;
}

int main() {
    cin >> n >> m >> t;

    int r, c, w;
    char d;
    for (int i = 0; i < m; i++) {
        cin >> r >> c >> d >> w;

        int dir;
        if(d == 'L') dir = 0;
        else if(d == 'U') dir = 1;
        else if(d == 'R') dir = 2;
        else dir = 3;

        pair<int, int> pos = {r, c};
        balls[pos] = {i + 1, w, r, c, dir};
    }

    // Please write your code here.

    for(int i = 0; i < t; i++){
        move_all();
    }

    cout << balls.size() << " ";
    int max_weight = 0;
    for(auto [pos, ball]: balls){
        auto [idx, w, x, y, dir] = ball;

        max_weight = max(max_weight, w);
    }
    cout << max_weight;

    return 0;
}
