#include <iostream>
#include <string>

using namespace std;

int N;
string records;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    cin >> records;

    // Please write your code here.
    int out = 0;
    for(int i = 0; i < N; i++){
        if(records[i] == ')') out++;
    }

    int inside = 0;
    int need = N / 2 - out;
    for(int i = N - 1; i >= 0; i--){
        if(records[i] == ')') inside--;
        else if(records[i] == '(') inside++;
        else{
            if(need > 0){
                inside--;
                need--;
            }
            else inside++;
        }
        
        if(inside > 0) break;
    }

    if(inside == 0) cout << "Yes";
    else cout << "No";

    return 0;
}
