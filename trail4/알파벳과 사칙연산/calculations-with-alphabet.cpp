#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

string expression;
int value[6];
int ans = INT_MIN;

void check(){
    int cur = value[expression[0] - 'a'];
    for(int i = 1; i < expression.length(); i = i + 2){
        char cmd = expression[i];
        int v = value[expression[i + 1] - 'a'];

        if(cmd == '+'){
            cur += v;
        }
        else if(cmd == '-'){
            cur -= v;
        }
        else if(cmd == '*'){
            cur *= v;
        }
    }

    ans = max(ans, cur);
}

void back(int cnt){
    if(cnt == 6){
        check();
        return;
    }

    for(int i = 1; i <= 4; i++){
        value[cnt] = i;
        back(cnt + 1); 
    }
}

int main() {
    cin >> expression;

    // Please write your code here.

    back(0);
    cout << ans;

    return 0;
}
