#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int N;
vector<vector<pair<int, int>>> scores;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    scores.resize(4, vector<pair<int, int>>(N));

    // i번 대회에서 j번 사람이 받은 점수
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < N; j++) {
            int score;
            cin >> score;
            scores[i][j] = {score, j};
            scores[3][j] = {scores[3][j].first + score, j};
        }
    }

    // 출력은
    // i번 대회에서 j번 사람의 등수.

    // Please write your code here.
    sort(scores[0].begin(), scores[0].end());
    sort(scores[1].begin(), scores[1].end());
    sort(scores[2].begin(), scores[2].end());
    sort(scores[3].begin(), scores[3].end());

    vector<vector<int>> ans(4, vector<int>(N));

    for(int i = 0; i < 4; i++){
        int rank = 1;
        int delay = 0;
        ans[i][scores[i][N - 1].second] = 1;

        for(int j = N - 2; j >= 0; j--){
            auto [score, idx] = scores[i][j];
            auto [pre_score, pre_idx] = scores[i][j + 1];

            // cout << score << ", " << idx << " <=> " << pre_score << ", " << pre_idx << " : " << j << endl;

            if(score == pre_score) {
                ans[i][idx] = rank;
                delay++;
            }
            else {
                rank += (delay + 1);
                delay = 0;
                ans[i][idx] = rank;
            }
        }
    }

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < N; j++){
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }


    return 0;
}
