#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

set<vector<int>> ans;
vector<int> vec;
int used[11] = {0, };
int N, M;

void back(int cnt, int start){
    // for(int i = 0; i < vec.size(); i++){
    //     cout << vec[i] << " ";
    // }
    // cout << endl;

    if(cnt == M){
        for(int i = 0; i < M; i++){
            cout << vec[i] << " ";
        }
        cout << endl;
        return;
    }

    for(int i = start; i <= N; i++){
        if(used[i] == 0){
            vec.push_back(i);
            used[i] = 1;

            back(cnt + 1, i + 1);

            vec.pop_back();
            used[i] = 0;
        }
    }
}

int main() {
    cin >> N >> M;

    // Please write your code here.
    back(0, 1);
    // for(const vector<int>& s : ans){
    //     for(int i = 0; i < M; i++){
    //         cout << s[i] << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}
