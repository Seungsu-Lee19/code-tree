#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> arr;
int used[9] = {0, };

void back(int cnt){
    if(cnt == n){
        for(int i = 0; i < n; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
        return;
    }

    for(int i = 1; i <= n; i++){
        if(used[i] == 0){
            arr.push_back(i);
            used[i] = 1;

            back(cnt + 1);
            
            arr.pop_back();
            used[i] = 0;
        }
    }
}

int main() {
    cin >> n;

    // Please write your code here.
    back(0);
    return 0;
}
