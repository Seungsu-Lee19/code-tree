#include <iostream>

using namespace std;

int grid[4][4];
char dir;

void add_L(){
    for(int x = 0; x < 4; x++){
        int idx = 0;
        for(int y = 1; y < 4; y++){
            if(grid[x][idx] == grid[x][y]){
                grid[x][idx] *= 2;
                grid[x][y] = 0;

                idx = y + 1;
                y++;
            }
            else if(grid[x][y]){
                idx = y;
            }
        }
    }

    // for(int i = 0; i < 4; i++){
    //     for(int j = 0; j < 4; j++){
    //         cout << grid[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
}
void add_R(){
    for(int x = 0; x < 4; x++){
        int idx = 3;
        for(int y = 2; y >= 0; y--){
            if(grid[x][idx] == grid[x][y]){
                grid[x][idx] *= 2;
                grid[x][y] = 0;

                
                idx = y - 1;
                y--;
                
                // for(int i = 0; i < 4; i++){
                //     for(int j = 0; j < 4; j++){
                //         cout << grid[i][j] << " ";
                //     }
                //     cout << endl;
                // }
                // cout << endl;
            }
            else if(grid[x][y]){
                idx = y;
            }
        }
    }

    // for(int i = 0; i < 4; i++){
    //     for(int j = 0; j < 4; j++){
    //         cout << grid[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
}
void add_U(){
    for(int y = 0; y < 4; y++){
        int idx = 0;
        for(int x = 1; x <= 3; x++){
            if(grid[idx][y] == grid[x][y]){
                grid[idx][y] *= 2;
                grid[x][y] = 0;
                
                idx = x + 1;
                x++;
            }
            else if(grid[x][y]){
                idx = x;
            }
        }
    }

    // for(int i = 0; i < 4; i++){
    //     for(int j = 0; j < 4; j++){
    //         cout << grid[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
}
void add_D(){
    for(int y = 0; y < 4; y++){
        int idx = 3;
        for(int x = 2; x >= 0; x--){
            if(grid[idx][y] == grid[x][y]){
                grid[idx][y] *= 2;
                grid[x][y] = 0;

                idx = x - 1;
                x--;
            }
            else if(grid[x][y]){
                idx = x;
            }
        }
    }

    // for(int i = 0; i < 4; i++){
    //     for(int j = 0; j < 4; j++){
    //         cout << grid[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
}

int main() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> grid[i][j];
        }
    }

    cin >> dir;

    // Please write your code here.
    int temp[4][4] = {0, };
    int idx = 0;

    if(dir == 'L'){
        add_L();
        
        for(int x = 0; x < 4; x++){
            idx = 0;
            for(int y = 0; y < 4; y++){
                if(grid[x][y]){
                    temp[x][idx] = grid[x][y];
                    idx++;
                }
            }
        }
    }
    else if(dir == 'U'){
        add_U();
        
        for(int y = 0; y < 4; y++){
            idx = 0;
            for(int x = 0; x < 4; x++){
                if(grid[x][y]){
                    temp[idx][y] = grid[x][y];
                    idx++;
                }
            }
        }
    }
    else if(dir == 'R'){
        add_R();
        
        for(int x = 0; x < 4; x++){
            idx = 3;
            for(int y = 3; y >= 0; y--){
                if(grid[x][y]){
                    temp[x][idx] = grid[x][y];
                    idx--;
                }
            }
        }
    }
    else{
        add_D();

        for(int y = 0; y < 4; y++){
            idx = 3;
            for(int x = 3; x >= 0; x--){
                if(grid[x][y]){
                    temp[idx][y] = grid[x][y];
                    idx--;
                }
            }
        }
    }

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cout << temp[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
