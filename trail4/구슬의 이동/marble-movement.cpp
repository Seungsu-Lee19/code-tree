#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

vector<tuple<int, int, int, int, int>> vec;

int n, m, t, k;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

tuple<int, int, int, int, int> move(int x, int y, int d, int v, int idx){
    int nx, ny;
    for(int i = 1; i <= v; i++){
        nx = x + dx[d];
        ny = y + dy[d];

        if(nx < 1 || ny < 1 || nx > n || ny > n) {
            d = (d + 2) % 4;
            i--;

            continue;
        }

        x = nx;
        y = ny;
    }

    return {v, idx, x, y, d};
}

void moveAll(){
    vector<tuple<int, int, int, int, int>> temp;

    for(int i = 0; i < vec.size(); i++){
        auto [v, idx, x, y, d] = vec[i];
        
        temp.push_back(move(x, y, d, v, idx));
    }

    vec = temp;
}

void removeDuplicate(){
    int grid[51][51] = {0, };

    for(int i = 0; i < vec.size(); i++){
        auto [v, idx, x, y, d] = vec[i];

        grid[x][y]++;
    }

    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= n; j++){
    //         cout << grid[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    vector<tuple<int, int, int, int, int>> temp;
    sort(vec.begin(), vec.end());
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int cnt = 0;
            for(int p = vec.size() - 1; p >= 0; p--){
                auto [v, idx, x, y, d] = vec[p];
                if(i == x && j == y){
                    if(grid[i][j] > k){
                        if(cnt < k){
                            cnt++;
                            temp.push_back({v, idx, x, y, d});
                            // cout << "cnt   " << x << ", " << y << " => " << idx << ", " << v << endl;
                        }
                    }
                    else{
                        temp.push_back({v, idx, x, y, d});
                        // cout << x << ", " << y << " => " << idx << ", " << v << endl;
                    }
                }
            }
        }
    }

    vec = temp;
}

int main() {
    cin >> n >> m >> t >> k;

    int r, c, v;
    char d;

    for (int i = 0; i < m; i++) {
        cin >> r >> c >> d >> v;
        if(d == 'L') vec.push_back({v, i, r, c, 0});
        else if(d == 'U') vec.push_back({v, i, r, c, 1});
        else if(d == 'R') vec.push_back({v, i, r, c, 2});
        else vec.push_back({v, i, r, c, 3});
    }

    // Please write your code here.
    for(int i = 0; i < t; i++){
        moveAll();
        removeDuplicate();
    }

    cout << vec.size();

    return 0;
}
