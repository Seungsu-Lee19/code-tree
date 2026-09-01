#include <iostream>

using namespace std;

int N;
int x1, y1;
int x2, y2;

int main() {
    cin >> N;

    int grid[201][201] = {};

    for (int i = 0; i < N; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        x1 += 100;
        x2 += 100;
        y1 += 100;
        y2 += 100;

        for(int i = x1; i < x2; i++){
            for(int j = y1; j < y2; j++){
                grid[i][j] = 1;
            }
        }

    }

    // Please write your code here.
    int s = 0;
    for(int i = 0; i < 201; i++){
        for(int j = 0; j < 201; j++){
            s += grid[i][j];
        }
    }
    cout << s;
    

    return 0;
}