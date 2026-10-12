#include <iostream>
#include <vector>

using namespace std;

int n, q;

int main() {
    cin >> n >> q;

    int dest;
    vector<int> visited(n + 1);

    for (int i = 0; i < q; i++) {
        cin >> dest;

        int temp = dest;
        int ans = 0;
        while(temp >= 1){
            if(visited[temp] == 1){
                ans = temp;
            }

            temp /= 2;
        }

        cout << ans << "\n";

        if(ans == 0) visited[dest] = 1;
    }

    // Please write your code here.

    return 0;
}