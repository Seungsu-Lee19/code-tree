#include <iostream>
#include <algorithm>
#include <tuple>
#include <string>

using namespace std;

string name;
int height;
double weight;

bool cmp_name(const tuple<int, double, string> a, const tuple<int, double, string> b){
    return get<2>(a) < get<2>(b);
}
bool cmp_height(const tuple<int, double, string> a, const tuple<int, double, string> b){
    return get<0>(a) > get<0>(b);
}

int main() {
    tuple<int, double, string> t[5];
    for (int i = 0; i < 5; i++) {
        cin >> name >> height >> weight;
        t[i] = make_tuple(height, weight, name);
    }

    // Please write your code here.
    cout << fixed;
    cout.precision(1);
    
    sort(t, t + 5, cmp_name);
    cout << "name\n";
    for(int i = 0; i < 5; i++){
        tie(height, weight, name) = t[i];
        cout << name << " " << height << " " << weight << endl;
    }

    sort(t, t + 5, cmp_height);
    cout << "\nheight\n";
    for(int i = 0; i < 5; i++){
        tie(height, weight, name) = t[i];
        cout << name << " " << height << " " << weight << endl;
    }

    return 0;
}