#include <iostream>
#include <vector>

using namespace std;

int N, Q;
int x;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> Q;

    vector<vector<int>> sum(
        N + 1,
        vector<int> (4)
    );
    for (int i = 1; i <= N; i++) {
        cin >> x;
        // sum[i][x]++;
        for(int k = 1; k <= 3; k++){
            if(k == x) sum[i][k] = sum[i - 1][k] + 1;
            else sum[i][k] = sum[i - 1][k];
        }
    }

    // for(int i = 1; i <= N; i++){
    //     for(int j = 1; j <= 3; j++){
    //         cout << sum[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    for (int i = 0; i < Q; i++) {
        int a, b;
        cin >> a >> b;

        for(int k = 1; k <= 3; k++){
            cout << sum[b][k] - sum[a - 1][k] << " ";
        }
        cout << "\n";
    }

    // Please write your code here

    return 0;
}
