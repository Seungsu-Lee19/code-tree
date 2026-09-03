#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int grid[200][200];

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    int dx1[3] = {0, 0, 0};
    int dy1[3] = {0, -1, 1};
    
    int dx2[3] = {0, -1, 1};
    int dy2[3] = {0, 0, 0};
    
    int dx3[3] = {0, -1, 0};
    int dy3[3] = {0, 0, 1};
    
    int dx4[3] = {0, 0, 1};
    int dy4[3] = {0, 1, 0};
    
    int dx5[3] = {0, 0, 1};
    int dy5[3] = {0, -1, 0};
    
    int dx6[3] = {0, 0, -1};
    int dy6[3] = {0, -1, 0};

    int ans = 0;
    for(int x = 0; x < n; x++){
        for(int y = 0; y < m; y++){
            int nx, ny;
            int score = 0;
            for(int k = 0; k < 3; k++){
                nx = x + dx1[k];
                ny = y + dy1[k];
                if(nx >= 0 && ny >= 0 && nx < n && ny < m){
                    score += grid[nx][ny];
                }
                else{
                    score = 0;
                    break;
                }
            }
            ans = max(ans, score);

            score = 0;
            for(int k = 0; k < 3; k++){
                nx = x + dx2[k];
                ny = y + dy2[k];
                if(nx >= 0 && ny >= 0 && nx < n && ny < m){
                    score += grid[nx][ny];
                }
                else{
                    score = 0;
                    break;
                }
            }
            ans = max(ans, score);

            score = 0;
            for(int k = 0; k < 3; k++){
                nx = x + dx3[k];
                ny = y + dy3[k];
                if(nx >= 0 && ny >= 0 && nx < n && ny < m){
                    score += grid[nx][ny];
                }
                else{
                    score = 0;
                    break;
                }
            }
            ans = max(ans, score);

            score = 0;
            for(int k = 0; k < 3; k++){
                nx = x + dx4[k];
                ny = y + dy4[k];
                if(nx >= 0 && ny >= 0 && nx < n && ny < m){
                    score += grid[nx][ny];
                }
                else{
                    score = 0;
                    break;
                }
            }
            ans = max(ans, score);

            score = 0;
            for(int k = 0; k < 3; k++){
                nx = x + dx5[k];
                ny = y + dy5[k];
                if(nx >= 0 && ny >= 0 && nx < n && ny < m){
                    score += grid[nx][ny];
                }
                else{
                    score = 0;
                    break;
                }
            }
            ans = max(ans, score);

            score = 0;
            for(int k = 0; k < 3; k++){
                nx = x + dx6[k];
                ny = y + dy6[k];
                if(nx >= 0 && ny >= 0 && nx < n && ny < m){
                    score += grid[nx][ny];
                }
                else{
                    score = 0;
                    break;
                }
            }
            ans = max(ans, score);
        }
    }

    cout << ans;

    

    return 0;
}
