#include <iostream>
#include <vector>

using namespace std;

int n;

int main() {
    cin >> n;

    // Please write your code here.
    vector<int> stair(n + 1);
    stair[2] = 1;
    stair[3] = 1;
    
    for(int i = 4; i <= n; i++){
        if(stair[i - 2] + stair[i - 3] > 0) stair[i] = (stair[i - 2] + stair[i - 3]) % 10007;
    }

    if(stair[n] > 0) cout << stair[n] % 10007;
    else cout << 0;

    return 0;
}