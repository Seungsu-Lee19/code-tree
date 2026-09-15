#include <iostream>

using namespace std;

int n;
int grid[10];
int ans = 0;

bool check(){
    int prev = grid[0];
    int cnt = 1;
    for(int i = 1; i < n; i++){
        if(prev == grid[i]){
            cnt++;
        }
        else{
            if(cnt % prev != 0) return false;
            
            prev = grid[i];
            cnt = 1;
        }
    }

    if(prev != 1 && cnt % prev != 0) return false;

    // cout << endl;
    // cout << "a : " << prev << " " << cnt << endl;
    // for(int i = 0; i < n; i++){
    //     cout << grid[i] << " ";
    // }
    // cout << endl;

    return true;
}

void back(int cnt){
    // n자리 아름다운 수
    // 1 -1                                                 1
    // 2 - 11, 22                                           2
    // 3 - 111, 122, 221, 333                               4
    // 4 - 1111, 1122, 1221, 2211, 1333, 3331, 4444, 2222         8
    // 5 - 11111, 11122, 11221, 12211, 11333, 13331, 33311, 14444, 44441    
    if(cnt == n){
        if(check()) ans++;

        return;
    }

    for(int i = 1; i <= 4; i++){
        grid[cnt] = i;
        back(cnt + 1);
    }
}

int main() {
    cin >> n;

    // Please write your code here.
    back(0);
    cout << ans;

    return 0;
}
