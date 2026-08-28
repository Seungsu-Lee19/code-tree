#include <iostream>
#include <algorithm>

using namespace std;

int N;
int nums[2000];

int main() {
    cin >> N;

    for (int i = 0; i < 2 * N; i++) {
        cin >> nums[i];
    }

    // Please write your code here.
    sort(nums, nums + (2 * N));
    int m = -1;
    for(int i = 0; i < N; i++){
        int s = nums[i] + nums[2 * N - i - 1];
        m = max(m, s);
    }
    cout << m;
    return 0;
}
