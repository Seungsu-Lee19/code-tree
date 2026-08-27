#include <iostream>

using namespace std;

int a;
int c;
char o;

int main() {
    cin >> a >> o >> c;

    // Please write your code here.
    if(o == '+'){
        cout << a << " + " << c << " = " << a + c;
    }
    else if(o == '-'){
        cout << a << " - " << c << " = " << a - c;
    }
    else if(o == '/'){
        cout << a << " / " << c << " = " << a / c;
    }
    else if(o == '*'){
        cout << a << " * " << c << " = " << a * c;
    }
    else cout << "False";
    

    return 0;
}