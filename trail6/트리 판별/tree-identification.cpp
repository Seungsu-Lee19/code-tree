#include <iostream>
#include <map>
#include <vector>

using namespace std;

int m;
int ans = -1;

map<int, vector<int>> graph;
map<int, int> roots;

void dfs(int cur, int cnt){
    for(auto next: graph[cur]){
        roots[next] = -1;
        dfs(next, cnt + 1);
    }
}

int main() {
    cin >> m;

    int from, to;
    for (int i = 0; i < m; i++) {
        cin >> from >> to;

        graph[from].push_back(to);
        roots[to]++;
        roots[from] += 0;
    }

    // Please write your code here.
    int root = -1;
    for(auto [r, cnt]: roots){
        if(cnt == 0){
            if(root == -1) root = r;
            else{
                ans = 0;
                break;
            }
        }
        else if(cnt >= 2){
            ans = 0;
            break;
        }
    }

    if(ans == 0){
        cout << ans;
        return 0;
    }

    roots[root] = -1;
    dfs(root, 1);

    ans = 1;
    for(auto [node, cnt]: roots){
        if(cnt != -1){
            ans = 0;
            break;
        }
    }
    cout << ans;

    return 0;
}