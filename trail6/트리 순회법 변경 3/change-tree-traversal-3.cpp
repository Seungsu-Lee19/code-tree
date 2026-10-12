#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int n;

vector<int> in, post;
unordered_map<int, int> pos;

void dfs(int inL, int inR, int postL, int postR){
    if(inL > inR) return;

    int root = post[postR];
    int mid = pos[root];
    int left_size = mid - inL;

    cout << root << " ";
    dfs(inL, mid - 1, postL, postL + left_size - 1);
    dfs(mid + 1, inR, postL + left_size, postR - 1);
}

int main() {
    cin >> n;

    in.resize(n);
    post.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> in[i];
        pos[in[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        cin >> post[i];
    }

    // Please write your code here.
    dfs(0, n - 1, 0, n - 1);

    return 0;
}