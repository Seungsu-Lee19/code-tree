#include <iostream>

using namespace std;

int T;
int N, M;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

void move(int (&arr)[51][51][4], int (&temp)[51][51][4]){
    for(int k = 0; k < 4; k++){
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                if(arr[i][j][k]){
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if(nx < 1 || ny < 1 || nx > N || ny > N) {
                        temp[i][j][(k + 2) % 4]++;
                        continue;
                    }

                    temp[nx][ny][k]++;
                }
            }
        }
    }

    return;
}

int remove_ball(int (&arr)[51][51][4], int (&temp)[51][51][4]){
    int ret = 0;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            int cnt = 0;
            int p = 0;
            for(int k = 0; k < 4; k++){
                if(temp[i][j][k]) {
                    cnt++;
                    p = k;
                }
                arr[i][j][k] = 0;
            }


            if(cnt == 1) {
                arr[i][j][p] = 1;
                ret++;
            }
        }
    }

    return ret;
}


int main() {
    cin >> T;

    for (int t = 0; t < T; t++) {
        cin >> N >> M;

        int grid[51][51][4] = {0, };
        for (int i = 0; i < M; i++) {
            char d;
            int x;
            int y;
            cin >> x >> y >> d;

            if(d == 'L') grid[x][y][0] = 1;
            else if(d == 'U') grid[x][y][1] = 1;
            else if(d == 'R') grid[x][y][2] = 1;
            else grid[x][y][3] = 1;
        }

        int cnt = 0;
        int prev = 0;
        while(1){

            // 구슬 이동
            int temp[51][51][4] = {0, };
            move(grid, temp);
            // for(int i = 1; i <= N; i++) {
            //     for(int dir = 0; dir < 4; dir++) {
            //         for(int j = 1; j <= N; j++) {
            //             cout << temp[i][j][dir] << " ";
            //         }

            //         if(dir != 3)
            //             cout << "- ";
            //     }
            //     cout << '\n';
            // }
            // cout << "---------------------------------------\n";

            // 구슬 제거
            int ch = remove_ball(grid, temp);

            // 구슬 이동해도 의미 있나? check
            if(ch == prev) cnt++;
            else{
                cnt = 0;
                prev = ch;
            }

            if(cnt > 2 * N) {
                cout << ch << endl;
                break;
            }
            // if(check(temp)) break;
        }

        // cout << cnt << endl;        

    }

    return 0;
}
