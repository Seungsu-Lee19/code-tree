#include <iostream>

#define MAX_N 5

using namespace std;

class User {
    public:
        char code_name;
        int score;

        User(char code_name, int score){
            this->code_name = code_name;
            this->score = score;
        }
        User(){}
};

User users[MAX_N];

int main() {
    for (int i = 0; i < MAX_N; i++) {
        cin >> users[i].code_name >> users[i].score;
    }

    // Please write your code here.
    char min_name = users[0].code_name;
    int min_score = users[0].score;

    for(int i = 1; i < MAX_N; i++){
        if(users[i].score < min_score){
            min_score = users[i].score;
            min_name = users[i].code_name;
        }
    }

    cout << min_name << " " << min_score;

    return 0;
}
