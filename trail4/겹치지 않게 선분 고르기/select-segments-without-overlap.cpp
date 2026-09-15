#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int n, ans = 1;
vector<pair<int, int>> vec;
vector<int> idx;


int check(){
    int cnt = 0;

    return cnt;
}

void back(int cnt){
    // if(ans < (int)idx.size()){
    //     for(auto a : idx){
    //         cout << a << " ";
    //     }
    //     cout << endl;
    // }
    ans = max(ans, (int)idx.size());

    auto [l, r] = vec[cnt];
    for(int i = cnt + 1; i < n; i++){
        auto [l2, r2] = vec[i];

        if(r < l2){
            idx.push_back(i);
            back(i);
            idx.pop_back();
        }
    }
}

int main() {
    cin >> n;

    int l, r;
    for (int i = 0; i < n; i++) {
        cin >> l >> r;
        vec.push_back({l, r});
    }

    // Please write your code here.

    // 1번을 선택하고, 겹치지 않는 그 다음거 선택
    // 2번을 선택하고, 겹치지 않는 그 다음거 선택
    // ...

    sort(vec.begin(), vec.end());
    for(int i = 0; i < n - 1; i++){
        idx.push_back(i);
        back(i);
        idx.pop_back();
    }

    cout << ans;

    return 0;
}
