#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int n, m;

vector<int> which;
vector<pair<int, int>> grid;
vector<int> idx;

int ans;

bool findEnd(bool ver){
    vector<int> temp(n + 1);
    // cout << "1\n";

    for(int i = 1; i <= n; i++){
        int row = 1;
        int col = i;
        while(1){
            if(row == 16) break;

            if(ver){
                for(auto [x, y] : grid){
                    if(row == x && col == y){
                        col += 1;
                        break;
                    }
                    else if(row == x && col == y + 1){
                        col -= 1;
                        break;
                    }
                }
            }
            else{
                for(int k = 0; k < idx.size(); k++){
                    auto [x, y] = grid[idx[k]];
                    if(row == x && col == y){
                        col += 1;
                        break;
                    }
                    else if(row == x && col == y + 1){
                        col -= 1;
                        break;
                    }
                }
                
                // cout << i << " -> (" << row << ", " << col << ")\n";
            }

            row++;
            
        }
        temp[col] = i; 
    }

    if(ver) which = temp;
    else{
        for(int i = 1; i <= n; i++){
            if(which[i] != temp[i]) return false;
        }
    }

    return true;
}

void back(int cnt){
    // if(cnt == m) return;

    if(findEnd(false)){
        ans = min(ans, (int)idx.size());
    }

    for(int i = cnt; i < m; i++){
        idx.push_back(i);
        back(i + 1);
        idx.pop_back();
    }
}

int main() {
    cin >> n >> m;
    // n은 세로줄. 즉, 열
    // m은 가로줄의 수. 즉, 행

    int a, b;
    ans = m;
    // a ~ a + 1까지 세로줄. 즉, 열
    // b는 위에서부터 b번째 위치에 그어짐. 즉, 행
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        grid.push_back({b, a});
        // grid[b][a] = 1;
        // grid[b][a + 1] = 1;
    }

    // Please write your code here.

    // 사다리를 vector로 구성한다.
    // N개의 위치에서 1만날 때까지 내려가자가 만나면 1쪽으로 움직이고 다시 반복
    // 최종 위치 저장.

    // 하나씩 제거해봐야 한다.
    // 제거 후 다시 위치 파악 후 같다면 저장.

    which.resize(n + 1, 0);
    findEnd(true);
    back(0);

    cout << ans;

    // for(int i = 1; i <= n; i++){
    //     cout << which[i] << " ";
    // }

    return 0;
}
