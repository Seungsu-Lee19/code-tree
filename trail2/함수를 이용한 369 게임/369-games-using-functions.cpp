#include <iostream>
#include <string>

using namespace std;

int a, b;

int main() {
    cin >> a >> b;

    // Please write your code here.
    int cnt = 0;
    for(int i = a; i <= b; i++){
        if(i % 3 == 0){
            cnt += 1;
            continue;
        }

        string temp = to_string(i);
        if(temp.find('3') != string::npos) cnt += 1;
        else if(temp.find('6') != string::npos) cnt += 1;
        else if(temp.find('9') != string::npos) cnt += 1;
        
    }

    cout << cnt;

    return 0;
}