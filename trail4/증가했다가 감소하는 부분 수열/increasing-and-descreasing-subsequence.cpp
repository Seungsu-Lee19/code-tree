#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int sequence[1000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
    }

    // Please write your code here.
    vector<int> incr(n, 1);
    vector<int> decr(n, 1);

    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(sequence[i] > sequence[j]) incr[i] = max(incr[i], incr[j] + 1);
        }
    }

    for(int i = n - 1; i >= 0; i--){
        for(int j = i + 1; j < n; j++){
            if(sequence[i] > sequence[j]) decr[i] = max(decr[i], decr[j] + 1);
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        // cout << incr[i] << " " << decr[i] << endl;
        ans = max(ans, incr[i] + decr[i] - 1);
    }
    cout << ans;
    return 0;
}
