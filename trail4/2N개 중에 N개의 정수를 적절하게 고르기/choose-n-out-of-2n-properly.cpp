#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int n;
int num[20];
int ans = INT_MAX;

vector<int> idx;

void calc(){
    int sum1 = 0;
    int sum2 = 0;

    for(int i = 0; i < 2 * n; i++){
        auto it = find(idx.begin(), idx.end(), i);
        if(it == idx.end()){
            sum2 += num[i];
        }
        else{
            sum1 += num[*it];
        }
    }
    ans = min(ans, abs(sum1 - sum2));
}

void back(int cnt, int start){
    if(cnt == n){
        calc();
        return;
    }

    for(int i = start; i < 2 * n; i++){
        idx.push_back(i);
        back(cnt + 1, i + 1);
        idx.pop_back();
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < 2 * n; i++) {
        cin >> num[i];
    }

    // Please write your code here.
    back(0, 0);
    cout << ans;
    return 0;
}
