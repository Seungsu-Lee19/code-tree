#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

int main() {
    cin >> n >> m;
    
    vector<int> bombs;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        bombs.push_back(x);
    }

    // Please write your code here.
    while(1){
        if((int)bombs.size() == 0) break;

        int start = 0;
        int end = start + 1;
        int num = bombs[0];
        bool isBomb = false;
        vector<int> temp;
        vector<int> idx;

        for(int i = 1; i < bombs.size(); i++){
            if(num == bombs[i]){
                end++;
            }
            else{
                if(end - start >= m){
                    isBomb = true;
                    for(int k = start; k < end; k++) idx.push_back(k);
                }
                start = i;
                end = start + 1;
                num = bombs[i];
            }
        }

        if(end - start >= m){
            isBomb = true;
            for(int k = start; k < end; k++) idx.push_back(k);
        }

        if(isBomb == false) break;

        for(int i = 0; i < bombs.size(); i++){
            isBomb = false;
            for(int k = 0; k < idx.size(); k++){
                if(i == idx[k]){
                    isBomb = true;
                    break;
                }
            }

            if(!isBomb){
                temp.push_back(bombs[i]);
            }
        }

        bombs = temp;
        
        // for(int i = 0; i < bombs.size(); i++){
        //     cout << bombs[i] << endl;
        // }
        // cout << endl;
    }

    cout << bombs.size() << endl;
    for(int i = 0; i < bombs.size(); i++){
        cout << bombs[i] << endl;
    }
    

    return 0;
}
