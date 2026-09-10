#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int T;
int N, M;
int x;
int y;
char d;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

vector<tuple<int, int, int>> ball;

tuple<int, int, int> moveBall(int x, int y, int d){
    int nx = x + dx[d];
    int ny = y + dy[d];

    if(nx < 1 || ny < 1 || nx > N || ny > N) return {x, y, (d + 2) % 4};

    return {nx, ny, d};
}

void moveAll(){
    for(int i = 0; i < ball.size(); i++){
        auto [x, y, d] = ball[i];
        ball[i] = moveBall(x, y, d);
    }
}

void RemoveDuplicate(){
    int grid[51][51] = {0, };
    vector<tuple<int, int, int>> temp;
    
    for(int i = 0; i < ball.size(); i++){
        auto [x, y, d] = ball[i];
        grid[x][y]++;
    }

    for(int i = 0; i < ball.size(); i++){
        auto [x, y, d] = ball[i];
        if(grid[x][y] < 2) temp.push_back({x, y, d});
    }

    ball = temp;
}

int main() {
    cin >> T;

    for (int t = 0; t < T; t++) {
        cin >> N >> M;

        ball.clear();
        for (int i = 0; i < M; i++) {
            cin >> x >> y >> d;

            if(d == 'L') ball.push_back({x, y, 0});
            else if(d == 'R') ball.push_back({x, y, 2});
            else if(d == 'U') ball.push_back({x, y, 1});
            else ball.push_back({x, y, 3});
        }

        for(int k = 0; k < 2 * N; k++){
            moveAll();
            RemoveDuplicate();
        }

        cout << ball.size() << endl;
    }

    return 0;
}
