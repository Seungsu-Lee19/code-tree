#include <iostream>
#include <vector>

using namespace std;

vector<int> vec;
int K, N;

void check(){
    int start = vec[0];
    int cnt = 1;

    for(int i = 1; i < N; i++){
        if(start == vec[i]) cnt++;
        else{
            start = vec[i];
            cnt = 1;
        }

        if(cnt >= 3) return;
    }
    
    if(cnt >= 3) return;

    for(int i = 0; i < N; i++){
        cout << vec[i] << " ";
    }
    cout << "\n";
    return;
}

void back(int cnt){
    if(cnt == N){
        check();
        return;
    }

    for(int i = 1; i <= K; i++){
        vec[cnt] = i;
        back(cnt + 1);
    }
}

int main() {
    cin >> K >> N;

    // Please write your code here.
    vec.resize(N, 0);
    back(0);

    return 0;
}
