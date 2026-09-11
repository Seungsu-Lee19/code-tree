#include <iostream>
#include <tuple>
#include <utility>
#include <algorithm>
#include <map>

using namespace std;

int T;
int N;

// <weight, idx, x, y, dir>
// <weight, idx, x, y, dir>
using Ball = tuple<int, int, int, int, int>;

// key: <x, y>
// value: Ball
using BallMap = map<pair<int, int>, Ball>;

BallMap balls;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};


bool simul(){
    bool is_duplicate = false;
    BallMap next_balls;

    for(auto [pos, ball]: balls){
        auto [w, idx, x, y, dir] = ball;

        int nx = x + dx[dir];
        int ny = y + dy[dir];


        if (nx < -2000 || nx > 2000 ||
            ny < -2000 || ny > 2000) {
            continue;
        }

        pair<int, int> next_pos = {nx, ny};
        tuple<int, int, int, int, int> next_ball = {w, idx, nx, ny, dir};

        if(next_balls.find(next_pos) == next_balls.end()){
            next_balls[next_pos] = next_ball;
        }
        else{
            is_duplicate = true;
            if(next_balls[next_pos] < next_ball){
                next_balls[next_pos] = next_ball;
            }
        }
    }

    balls = next_balls;

    return is_duplicate;
}

int main() {
    cin >> T;

    int x, y, w;
    char d;
    for (int t = 0; t < T; t++) {
        cin >> N;
    
        for (int i = 0; i < N; i++) {
            cin >> x >> y >> w >> d;

            x *= 2;
            y *= 2;

            if(d == 'L') balls[{x, y}] = {w, i + 1, x, y, 0};
            else if(d == 'U') balls[{x, y}] = {w, i + 1, x, y, 1};
            else if(d == 'R') balls[{x, y}] = {w, i + 1, x, y, 2};
            else if(d == 'D') balls[{x, y}] = {w, i + 1, x, y, 3};
        }

        int time = 0;
        for(int i = 1; i <= 4000; i++){
            if(simul()){
                time = i;
            }

            if(balls.size() <= 1) break;
        }

        if(time == 0) cout << -1 << endl;
        else cout << time << endl;

    }

    return 0;
}