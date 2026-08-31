#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Weather{
    public:
        string date;
        string day;
        string weather;

        Weather(string date, string day, string w){
            this->date = date;
            this->day = day;
            this->weather = w;
        }
        Weather(){}
};

bool cmp(const Weather& a, const Weather& b){
    return a.date < b.date;
}

int n;
string date[100];
string day[100];
string weather[100];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> date[i] >> day[i] >> weather[i];
    }

    // Please write your code here.
    Weather weathers[n];
    for (int i = 0; i < n; i++) {
        weathers[i] = Weather(date[i], day[i], weather[i]);
    }

    sort(weathers, weathers + n, cmp);
    for (int i = 0; i < n; i++) {
        if(weathers[i].weather == "Rain"){
            cout << weathers[i].date << " " << weathers[i].day << " " << weathers[i].weather;
            break;
        }
    }

    return 0;
}