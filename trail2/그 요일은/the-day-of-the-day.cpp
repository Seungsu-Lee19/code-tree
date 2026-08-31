#include <iostream>

using namespace std;

int m1, m2, d1, d2;
string A;

int main() {
    cin >> m1 >> d1 >> m2 >> d2;
    cin >> A;

    // Please write your code here.
    int dates[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string days[7] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};

    int date = d2 - d1;
    for(int i = m1; i < m2; i++){
        date += dates[i];
    }

    int ans = date / 7;
    int idx;
    for(int i = 0; i < 7; i++){
        if(days[i] == A){
            idx = i;
            break;
        }
    }
    if(date % 7 >= idx) ans += 1;

    cout << ans;

    return 0;
}