#include <iostream>
#include <string>

using namespace std;

int n;
string ans;
string arr; 
bool isFind = false;

bool check(){
    int size = arr.size();
    for(int len = 1; len * 2 <= size; len++){
        string p = arr.substr(size - len * 2, len);
        string q = arr.substr(size - len, len);

        if(p == q) return false;
    }

    return true;
}

void back(int cnt){
    if(cnt == n){
        ans = arr;
        isFind = true;
        return;
    }

    if(isFind) return;

    for(int i = 4; i <= 6; i++){
        arr.push_back(i + '0');
        if(check()) back(cnt + 1);
        arr.pop_back();
        
        if(isFind) return;
    }
}

int main() {
    cin >> n;

    // Please write your code here.
    for(int i = 0; i < n; i++){
        ans.push_back('6');
    }
    back(0);

    cout << ans;
    return 0;
}
