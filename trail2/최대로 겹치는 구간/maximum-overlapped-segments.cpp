#include <iostream>
#include <algorithm>

using namespace std;

int n;
int x1, x2;

int main() {
    cin >> n;

    int check[201] = {0, };

    for (int i = 0; i < n; i++) {
        cin >> x1 >> x2;
        x1 += 100;
        x2 += 100;
        for(int j = x1; j < x2; j++){
            check[j]++;
            // cout << check[j] << " " << j << endl;
        }
    }

    // Please write your code here.
    cout << *max_element(check, check + 201);

    return 0;
}