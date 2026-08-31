#include <iostream>
#include <string>

using namespace std;

int m1, d1, m2, d2;

int main() {
    cin >> m1 >> d1 >> m2 >> d2;

    // Please write your code here.
    int dates[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string days[7] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};

    int date1 = d1;
    for(int i = 1; i < m1; i++){
        date1 = date1 + dates[i];
    }
    
    int date2 = d2;
    for(int i = 1; i < m2; i++){
        date2 = date2 + dates[i];
    }
    
    cout << days[((date2 - date1 % 7) + 7) % 7];

    return 0;
}