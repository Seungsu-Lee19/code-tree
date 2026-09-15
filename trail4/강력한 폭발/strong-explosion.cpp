#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int n;
vector<pair<int, int>> bomb;
vector<vector<int>> visited;
int ans = 0;

int dx[12] = {-1, -2, 1, 2, -1, 1, 0, 0, -1, -1, 1, 1};
int dy[12] = {0, 0, 0, 0, 0, 0, -1, 1, -1, 1, 1, -1};
// 0 - 0 ~ 3  - 1
// 1 - 4 ~ 7  - 2
// 2 - 8 ~ 11 - 3


void boom(){
    vector<vector<int>> temp(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(visited[i][j] >= 0){
                temp[i][j] = 1;
                for(int k = visited[i][j] * 4; k < visited[i][j] * 4 + 4; k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

                    temp[nx][ny] = 1;
                }
            }
        }
    }

    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(temp[i][j]) cnt++;
        }
    }

    ans = max(ans, cnt);
}

void back(int cnt, int ver){
    if(cnt == bomb.size()){
        boom();
        return;
    }    

    auto [x, y] = bomb[cnt];
    for(int i = 0; i < 3; i++){
        int temp = visited[x][y];
        visited[x][y] = i;
        back(cnt + 1, i);
        visited[x][y] = temp;
    }
}

int main() {
    cin >> n;

    int v;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v;
            if(v == 1) bomb.push_back({i, j});
        }
    }

    // Please write your code here.
    // 총 3가지 종류의 폭탄을 터트려 최대화
    // 총 가지수는 3의 (1의 개수)승
    // back에서 이미 터트린 폭탄(visited)만 아니면 3가지 중 하나 터트리고 다시 back
    // back에서 폭탄을 다 터트렸으면, 개수 새고 그전 버전으로 복귀
    visited.resize(n, vector<int>(n, -1));
    back(0, 0);
    cout << ans;

    return 0;
}
