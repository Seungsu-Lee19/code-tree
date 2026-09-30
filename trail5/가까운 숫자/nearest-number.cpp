#include <iostream>
#include <set>

using namespace std;

int n;
long long queries;

int main() {
    cin >> n;

    set<long long> se;
    se.insert(0);

    long long dist = 1000000001;
    for (int i = 0; i < n; i++) {
        cin >> queries;

        auto it = se.lower_bound(queries);
        long long start;
        if(it == se.end()) {
            it--;
            start = *it;
            if(queries - start < dist){
                dist = queries - start;
            }
        }
        else{
            start = *it;
            if(start - queries < dist){
                dist = start - queries;
            }
            
            it--;
            start = *it;
            if(queries - start < dist){
                dist = queries - start;
            }
        }

        se.insert(queries);

        cout << dist << endl;
        
    }

    // Please write your code here.

    return 0;
}
