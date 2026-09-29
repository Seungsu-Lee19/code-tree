#include <iostream>
#include <set>

using namespace std;

int T;
int k;
char command;
int n;

int main() {
    cin >> T;

    for (int t = 0; t < T; t++) {
        cin >> k;
        set<int> se;
        for (int i = 0; i < k; i++) {
            cin >> command >> n;
            
            if(command == 'I') se.insert(n);
            else{
                if(n < 0){
                    if(!se.empty()) se.erase(*se.begin());
                }
                else{
                    if(!se.empty()) se.erase(*se.rbegin());
                }
            }
        }

        if(se.empty()) cout << "EMPTY\n";
        else cout << *se.rbegin() << " " << *se.begin() << endl;
    }
    


    return 0;
}
