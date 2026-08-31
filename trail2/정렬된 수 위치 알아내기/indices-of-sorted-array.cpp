#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

int N;

int main() {
    cin >> N;

    int sequence1[N];
    int sequence2[N];
    bool isUsed[N] = {false, };
    // pair<int, int> p[N];
    for (int i = 0; i < N; i++) {
        cin >> sequence1[i];
        sequence2[i] = sequence1[i];
        // p[i] = make_pair(sequence, i + 1);
    }

    // Please write your code here.
    sort(sequence1, sequence1 + N);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(sequence2[i] == sequence1[j] && isUsed[j] == false){
                isUsed[j] = true;
                cout << j + 1 << " ";
                break;
            }
        }
    }

    return 0;
}
