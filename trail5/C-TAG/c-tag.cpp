#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int n, m;
string A[500];
string B[500];

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) cin >> A[i];

    for (int i = 0; i < n; i++) cin >> B[i];

    // Please write your code here.

    // m 자리중 3자리를 뽑아 A와 B가 달라야 함.
    // 

    
    

    int ans = 0;

    for(int i = 0; i < m - 2; i++){
        for(int j = i + 1; j < m - 1; j++){
            for(int k = j + 1; k < m; k++){
                unordered_set<string> se1;
                unordered_set<string> se2;

                for(int p = 0 ; p < n; p++){
                    string str1 = A[p];
                    string str2 = B[p];

                    string new_str1 = {str1[i], str1[j], str1[k]};
                    string new_str2 = {str2[i], str2[j], str2[k]};

                    se1.insert(new_str1);
                    se2.insert(new_str2);
                }

                bool overlap = false;

                for(const auto& x: se2){
                    if(se1.find(x) != se1.end()){
                        overlap = true;
                        break;
                    }
                }

                if(!overlap) ans++;
            }
        }
    }

    cout << ans;
    

    return 0;
}
