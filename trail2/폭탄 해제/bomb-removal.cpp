#include <iostream>
#include <string>

using namespace std;

class Bomb {
    public:
        string unlock_code;
        char wire_color;
        int seconds;

        Bomb(string s, char c, int sec){
            this->unlock_code = s;
            this->wire_color = c;
            this->seconds = sec;
        }
};

string unlock_code;
char wire_color;
int seconds;

int main() {
    cin >> unlock_code >> wire_color >> seconds;

    // Please write your code here.
    Bomb b = Bomb(unlock_code, wire_color, seconds);
    
    cout << "code : " << b.unlock_code << endl;
    cout << "color : " << b.wire_color << endl;
    cout << "second : " << b.seconds;

    return 0;
}