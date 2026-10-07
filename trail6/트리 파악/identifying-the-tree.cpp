#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int n;
int sum = 0;

unordered_map<int, vector<int>> graph;
vector<int> visited;

void dfs(int cur){
    int cnt = 0;

    for(int next: graph[cur]){
        if(visited[next] == -1){
            visited[next] = visited[cur] + 1;
            dfs(next);
            cnt++;
        }
    }

    if(cnt == 0) sum += visited[cur];
}

int main() {
    cin >> n;

    int from, to;
    for (int i = 0; i < n - 1; i++) {
        cin >> from >> to;

        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    visited.resize(n + 1, -1);
    visited[1] = 0;
    dfs(1);

    cout << sum % 2;

    return 0;
}