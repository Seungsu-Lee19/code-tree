#include <iostream>
#include <vector>

#define MAX_N 100000
#define MAX_K 10

using namespace std;

// 변수 선언:
int n, k;
vector<int> edges[MAX_N + 1];
bool visited[MAX_N + 1];
int a[MAX_N + 1];
int dp[MAX_N + 1][MAX_K + 1][2];
int ans;

// 1번 노드를 시작으로 DFS를 진행하며 값을 갱신합니다.
// dp[x][i][j] = x번 노드를 루트로 하는 서브트리에서 i개를 색칠했을 때의 최댓값
// (j == 1일 경우 j번 노드를 색칠, j == 0일 경우 j번 노드를 색칠하지 않음)
void DFS(int x) {
    int left_num = 0;
    int right_num = 0;

    // 현재 노드를 최초로 색칠하는 경우에 대한 초기조건입니다.
    dp[x][1][1] = a[x];
    // 현재 노드를 칠하지 않는 경우에 대한 초기조건입니다.
    dp[x][0][0] = 0;

    // 노드 x에 연결된 간선을 살펴보며 전부 방문해줍니다.
    for(int i = 0; i < (int) edges[x].size(); i++) {
        int y = edges[x][i];

        // 이미 방문한 정점이라면 스킵해줍니다.
        if(visited[y]) 
            continue;

        visited[y] = true;
        DFS(y);

        // dp값들을 점화식에 따라 채워줍니다.

        // x번 노드를 색칠하는 경우이며 동시에 총 i개의 노드가 색칠되었기를 바라는 순간이라면
        // 지금까지의 자식들 가지고는 i - j개의 노드를 칠했으며 x번 노드 자체는 색칠이 되어야 하고
        // 자식 노드 y에서 정확히 j개의 노드를 칠하고 동시에 y번 노드 자체는 색칠이 되지 않아야 합니다.
        for(int i = k; i >= 1; i--)
            for(int j = 1; j <= i; j++)
                dp[x][i][1] = max(dp[x][i][1], dp[x][i - j][1] + dp[y][j][0]);

        // x번 노드를 색칠하지 않은 경우이며 동시에 총 i개의 노드가 색칠되었기를 바라는 순간이라면
        // 지금까지의 자식들 가지고는 i - j개의 노드를 칠했으며 x번 노드 자체는 색칠이 되지 않아야 하고
        // 자식 노드 y에서 정확히 j개의 노드를 칠하고 동시에 y번 노드 자체는 색칠이 되던 말던 상관이 없습니다.
        for(int i = k; i >= 0; i--)
            for(int j = 0; j <= i; j++)
                dp[x][i][0] = max(dp[x][i][0], 
                                  dp[x][i - j][0] + 
                                  max(dp[y][j][0], dp[y][j][1]));
    }
}

int main() {
    // 입력:
    cin >> n;

    // n - 1개의 간선 정보를 입력받습니다.
    for(int i = 1; i <= n - 1; i++) {
        int x, y;
        cin >> x >> y;
        
        // 간선 정보를 인접리스트에 넣어줍니다.
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    // n개의 노드에 적힌 값을 입력받습니다.
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    cin >> k;

    // 1번 노드를 시작으로 DFS를 진행하며 값을 갱신합니다.
    visited[1] = true;
    DFS(1);

    // 모든 dp의 값 중 최댓값을 출력합니다.
    // 최대 i개의 노드를 색칠하는 경우를 전부 탐색합니다.
    for(int i = 1; i <= k; i++) {
        ans = max(ans, dp[1][i][0]);
        ans = max(ans, dp[1][i][1]);
    }

    cout << ans;
    return 0;
}
