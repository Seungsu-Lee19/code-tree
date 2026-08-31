#include <iostream>
#include <string>

#define MAX_N 10

using namespace std;

class People{
    public:
        string name;
        string address;
        string region;

        People(string n, string a, string r){
            this->name = n;
            this->address = a;
            this->region = r;
        }
        People(){}
};

int n;
string name[MAX_N], address[MAX_N], region[MAX_N];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> name[i] >> address[i] >> region[i];
    }

    // Please write your code here.
    People person[n];
    for (int i = 0; i < n; i++) {
        person[i] = People(name[i], address[i], region[i]);
    }

    int min_idx = 0;
    for (int i = 1; i < n; i++) {
        if(person[min_idx].name < person[i].name){
            min_idx = i;
        }
    }

    cout << "name " << person[min_idx].name << endl;
    cout << "addr " << person[min_idx].address << endl;
    cout << "city " << person[min_idx].region;


    return 0;
}
