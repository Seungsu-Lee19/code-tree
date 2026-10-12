#include <iostream>

using namespace std;

int n;
long long k;
int left_num[200001];
int right_num[200001];

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> left_num[i] >> right_num[i];
    }

    cin >> k;

    int node = 1;

    while(1){
        if(left_num[node] == -1 && right_num[node] == -1){
            cout << node;
            break;
        }
        else if(left_num[node] != -1 && right_num[node] == -1){
            node = left_num[node];
        }
        else if(left_num[node] == -1 && right_num[node] != -1){
            node = right_num[node];
        }
        else{
            if(k % 2 == 0){
                k /= 2;
                node = right_num[node];
            }
            else{
                k = (k + 1) / 2;
                node = left_num[node];
            }
        }
    }

    return 0;
}