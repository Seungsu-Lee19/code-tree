#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<vector<vector<int>>> edges;
int S, T;

vector<bool> bfs(int start, int finish, int idx){
    vector<bool> visited(n + 1);
    queue<int> q;

    visited[start] = true;
    visited[finish] = true;
    q.push(start);

    while(!q.empty()){
        int x = q.front();
        q.pop();

        for(int next: edges[idx][x]){
            if(!visited[next]){
                visited[next] = true;
                q.push(next);
            }
        }
    }

    return visited;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    edges.resize(2, vector<vector<int>>(n + 1));

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;

        edges[0][x].push_back(y);
        edges[1][y].push_back(x);
    }

    cin >> S >> T;

    vector<bool> visit1 = bfs(S, T, 0);
    vector<bool> visit2 = bfs(T, S, 0);
    vector<bool> visit3 = bfs(S, 0, 1);
    vector<bool> visit4 = bfs(T, 0, 1);
    
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(visit1[i] && visit2[i] && visit3[i] && visit4[i]) cnt++;
    }

    cout << cnt - 2;

    return 0;
}
