#include <iostream>

using namespace std;

int m1, d1, m2, d2;

int main() {
    cin >> m1 >> d1 >> m2 >> d2;

    // Please write your code here.
    int day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int date = d2 - d1 + 1;

    for(int i = m1; i < m2; i++){
        date += day[i];
    }

    cout << date;

    return 0;
}