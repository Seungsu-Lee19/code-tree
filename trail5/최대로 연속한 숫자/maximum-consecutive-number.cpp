#include <iostream>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int n, m;

int main() {
    cin >> n >> m;

    // nums를 set에 추가
    // 

    set<int> se; // 삭제된 번호
    se.insert(-1);
    se.insert(n + 1);

    map<int, int> mp; // 구간길이 l, 개수
    mp[n + 1] = 1; 

    int nums;
    for (int i = 0; i < m; i++) {
        cin >> nums;
        
        auto right = se.upper_bound(nums);
        int r = *right;

        --right;
        int l = *right;

        int old_l = r - l - 1;

        mp[old_l]--;

        if(mp[old_l] == 0) mp.erase(old_l);

        int left_l = nums - l - 1;
        int right_l = r - nums - 1;

        if(left_l > 0) mp[left_l]++;
        if(right_l > 0) mp[right_l]++;

        se.insert(nums);

        cout << mp.rbegin()->first << "\n";

    }

    // Please write your code here.

    return 0;
}
