#include <iostream>
#include <map>
#include <tuple>

using namespace std;

int T;
int N;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

// <weight, idx, x, y, dir>
using Ball = tuple<int, int, int, int, int>;

// key: <x, y>
// value: Ball
using BallMap = map<pair<int, int>, Ball>;

int move_all(BallMap& balls) {
    BallMap next;
    int collision_time = false;

    for (auto [pos, ball] : balls) {
        auto [w, idx, x, y, dir] = ball;

        int nx = x + dx[dir];
        int ny = y + dy[dir];

        // 범위를 벗어난 원자는 버림
        if (nx < -2000 || nx > 2000 ||
            ny < -2000 || ny > 2000) {
            continue;
        }

        pair<int, int> next_pos = {nx, ny};
        Ball next_ball = {w, idx, nx, ny, dir};

        auto it = next.find(next_pos);

        // 해당 위치에 원자가 없음
        if (it == next.end()) {
            next[next_pos] = next_ball;
        }
        // 해당 위치에 이미 원자가 있음 → 충돌
        else {
            collision_time = true;

            // 더 무거운 원자를 남김
            if (next_ball > it->second) {
                it->second = next_ball;
            }
        }
    }

    balls = next;

    return collision_time;
}

int main() {
    cin >> T;

    while (T--) {
        cin >> N;

        BallMap balls;

        for (int i = 0; i < N; i++) {
            int x, y, w;
            char d;

            cin >> x >> y >> w >> d;

            x *= 2;
            y *= 2;

            int dir;

            if (d == 'L') dir = 0;
            else if (d == 'U') dir = 1;
            else if (d == 'R') dir = 2;
            else dir = 3;  // D

            balls[{x, y}] = {w, i + 1, x, y, dir};
        }

        int answer = -1;

        for (int time = 1; time <= 4000; time++) {
            if (move_all(balls)) {
                answer = time;
            }

            // 원자가 1개 이하라면 더 이상 충돌 불가능
            if (balls.size() <= 1) {
                break;
            }
        }

        cout << answer << '\n';
    }

    return 0;
}