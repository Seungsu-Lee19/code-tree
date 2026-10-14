#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string message;
string key;

int main() {
    cin >> message >> key;

    vector<int> alpha(26);
    unordered_map<int, pair<int, int>> encoding;
    vector<vector<int>> encoding_pos(5, vector<int>(5));

    // 1. key를 먼저 만든다.
    // 1-1. i, j 순으로 key값을 넣는다
    // 1-2. 만약 이미 들어가 있는 값이면 continue
    // 1-3. 나머지 i, j에 들어가지 않은 알파벳을 넣는다.
    int x = 0, y = 0;
    for(char c: key){
        int idx = c - 'A';

        if(alpha[idx] == 0){
            encoding[idx] = {x, y};
            encoding_pos[x][y] = idx;
            alpha[idx] = 1;

            y += 1;
            if(y > 4){
                y %= 5;
                x++;
            }
        }
    }

    for(int i = 0; i < 26; i++){
        if(alpha[i] == 0 && i != 'J' - 'A'){
            encoding[i] = {x, y};
            encoding_pos[x][y] = i;
            alpha[i] = 1;

            y += 1;
            if(y > 4){
                y %= 5;
                x++;
            }
        }
    }

    // for(auto [k, v]: encoding){
    //     cout << k << " : " << v.first << " " << v.second << "\n";
    // }

    

    // 2. message를 앞에서 부터 2개씩 묶는다.
    // 2-1. 만약 같은 문자면 X를 넣는다.
    // 2-2. 그래도 같은 문자면(X 일 경우) Q를 넣는다.
    string new_msg;
    for(int i = 0; i < message.length(); i++){
        new_msg += message[i];

        if(i + 1 < message.length()){
            if(message[i] != message[i + 1]){
                new_msg = new_msg + message[i + 1];
                i++;
            }
            else{
                if(message[i] == 'X'){
                    new_msg = new_msg + 'Q';
                }
                else{
                    new_msg = new_msg + 'X';
                }
            }
        }
    }

    if(new_msg.length() % 2 != 0) new_msg += 'X';

    // cout << new_msg << endl;

    // 3. 두 문자씩 비교한다.
    // 3-1. key의 같은 행에 존재하면, 두 문자를 key 기준으로 한칸씩 오른쪽으로 밀어서 암호화.
    // 3-2. key의 같은 열에 존재하면, 두 문자를 key 기준으로 한칸씩 아래로 밀어서 암호화.
    // 3-3-1. 둘다 아니면, 첫번째 글자는 같은 행의 두번째 글자의 열로 변경.
    // 3-3-2. 둘다 아니면, 두번째 글자는 같은 행의 첫번째 글자의 열로 변경.

    string ans;

    for(int i = 0; i < new_msg.length() - 1; i = i + 2){
        auto [left_x, left_y] = encoding[new_msg[i] - 'A'];
        auto [right_x, right_y] = encoding[new_msg[i + 1] - 'A'];

        if(left_x == right_x){ // 같은 행
            left_y = (left_y + 1) % 5;
            right_y = (right_y + 1) % 5;

            ans.push_back(encoding_pos[left_x][left_y] + 'A');
            ans.push_back(encoding_pos[right_x][right_y] + 'A');
        }
        else if(left_y == right_y){
            left_x = (left_x + 1) % 5;
            right_x = (right_x + 1) % 5;

            ans.push_back(encoding_pos[left_x][left_y] + 'A');
            ans.push_back(encoding_pos[right_x][right_y] + 'A');
        }
        else{
            swap(left_y, right_y);

            ans.push_back(encoding_pos[left_x][left_y] + 'A');
            ans.push_back(encoding_pos[right_x][right_y] + 'A');
        }
    }
    
    cout << ans;

    return 0;
}
