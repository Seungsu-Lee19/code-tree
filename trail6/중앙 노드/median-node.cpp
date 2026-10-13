#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, r;

vector<vector<int>> graph;
vector<bool> visited;
vector<int> dp;

void dfs(int node){
    dp[node] = 1;
    for(int next: graph[node]){
        if(!visited[next]){
            visited[next] = true;
            dfs(next);
            dp[node] += dp[next];
        }
    }
}

int main() {
    cin >> n >> r;

    graph.resize(n + 1);
    dp.resize(n + 1);
    visited.resize(n + 1);

    int from, to;
    for (int i = 0; i < n - 1; i++) {
        cin >> from >> to;

        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    int center;
    int node = r;
    int prev = 0;
    while(1){
        if(r == node){
            if(graph[node].size() >= 2){
                center = r;
                break;
            }
            else{
                prev = node;
                node = graph[node][0];
            }
        }
        else if(graph[node].size() >= 3){
            center = node;
            break;
        }
        else if(graph[node].size() == 2){
            int temp = (graph[node][0] == prev)? graph[node][1] : graph[node][0];
            prev = node;
            node = temp;
        }
        else{
            center = node;
            break;
        }
    }

    visited[center] = true;
    dfs(center);

    // for(int i = 1; i <= n; i++){
    //     cout << dp[i] << " ";
    // }
    // cout << endl;

    int max_cnt = 0;
    int min_cnt = n;
    for(int child: graph[center]){
        max_cnt = max(max_cnt, dp[child]);
        min_cnt = min(min_cnt, dp[child]);
    }
    // cout << max_cnt << " " << min_cnt << endl;

    cout << max_cnt - min_cnt;

    return 0;
}