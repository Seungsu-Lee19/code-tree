#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string A;

int main() {
    cin >> A;

    // Please write your code here.
    int ans = 21;
    for(int i = 0; i < A.length(); i++){
        rotate(A.begin(), A.end() - 1, A.end());

        int start = 0;
        int cnt = 1;
        string temp(1, A[start]);
        for(int idx = 1; idx < A.length(); idx++){
            if(A[start] == A[idx]) cnt++;
            else{
                temp = temp + to_string(cnt);
                temp.push_back(A[idx]);
                start = idx;
                cnt = 1;
            }
        }
        temp = temp + to_string(cnt);

        ans = min(ans, (int)temp.length());
        // cout << temp << endl;
    }

    cout << ans;

    return 0;
}
