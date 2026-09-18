#include <iostream>
#include <vector>

using namespace std;

int n;
int used[9] = {0, };
vector<int> arr;

void back(int cnt){
    if(cnt == n){
        for(int i = 0; i < n; i++){
            cout << arr[i] << " ";
        }
        cout << endl;

        return;
    }

    for(int i = n; i > 0; i--){
        if(used[i] == 0){
            used[i] = 1;
            arr.push_back(i);

            back(cnt + 1);

            used[i] = 0;
            arr.pop_back();
        }
    }
}

int main() {
    cin >> n;

    // Please write your code here.
    back(0);

    return 0;
}
