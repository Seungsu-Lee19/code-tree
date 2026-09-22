#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;

int bfs(int start){
    queue<int> q;
    vector<int> visited(N + 2, -1);

    q.push(start);
    visited[start] = 0;


    while(!q.empty()){
        int n = q.front();
        q.pop();

        if(n == 1) return visited[n];
        
        if(n < 1) continue;

        if(visited[n - 1] == -1) {
            q.push(n - 1);
            visited[n - 1] = visited[n] + 1;
        }
        if(n % 2 == 0 && visited[n / 2] == -1) {
            q.push(n / 2);
            visited[n / 2] = visited[n] + 1;
        }
        if(n % 3 == 0 && visited[n / 3] == -1) {
            q.push(n / 3);
            visited[n / 3] = visited[n] + 1;
        }
        if(n + 1 < N + 2 && visited[n + 1] == -1){
            q.push(n + 1);
            visited[n + 1] = visited[n] + 1;
        }
    }

    return -1;
}

int main() {
    cin >> N;

    // Please write your code here.

    cout << bfs(N);

    return 0;
}
