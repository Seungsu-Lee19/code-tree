#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <climits>

using namespace std;

int Q, N;

long long max_food = 0;

long long acc = 0;

vector<long long> foods;
vector<long long> prefix;

long long cost(int k) {
    return (long long)k * foods[k - 1] - prefix[k];
}

long long winter(long long p) {
    int lo = 1, hi = foods.size();
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        if (cost(mid) <= p) lo = mid;
        else hi = mid - 1;
    }
    long long k = lo;

    long long realSum = prefix[k] + k * acc;
    return (realSum + p) / k;
}

void prefix_sum(int idx){
    prefix.resize(foods.size() + 1);
    for(int i = idx; i < foods.size(); i++){
        prefix[i + 1] = prefix[i] + foods[i];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> Q;

    
    int cmd;
    long long x;

    prefix.push_back(0);

    for(int i = 0; i < Q; i++){
        cin >> cmd >> x;

        if(cmd == 100){
            long long food;
            for(int q = 0; q < x; q++){
                cin >> food;
                foods.push_back(food);
            }

            sort(foods.begin(), foods.end());
            prefix_sum(0);
        }
        else if(cmd == 200){
            long long value = x - acc;

            int pos = upper_bound(foods.begin(), foods.end(), value) - foods.begin();
            foods.insert(foods.begin() + pos, value);
            prefix_sum(pos);
        }
        else if(cmd == 300){
            acc += x;
        }
        else if(cmd == 400){
            long long ans = winter(x);

            cout << ans << "\n";
        }
    }

    return 0;
}

