#include <iostream>
#include <vector>

using namespace std;

int N;

int main() {
    cin >> N;

    // Please write your code here.
    vector<int> fibo;
    fibo.push_back(0);
    fibo.push_back(1);
    fibo.push_back(1);

    for(int i = 3; i <= N; i++){
        fibo.push_back(fibo[i - 2] + fibo[i - 1]);
    }

    cout << fibo[N];

    return 0;
}
