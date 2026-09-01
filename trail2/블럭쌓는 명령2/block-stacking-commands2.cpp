#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
int A[100], B[100];

int main() {
    cin >> N >> K;

    int block[N + 1] = {0, };

    for (int i = 0; i < K; i++) {
        cin >> A[i] >> B[i];
        for(int j = A[i]; j <= B[i]; j++){
            block[j] += 1;
        }
    }

    // Please write your code here.
    cout << *max_element(block, block + N);

    return 0;
}