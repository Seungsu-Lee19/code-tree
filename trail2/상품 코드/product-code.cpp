#include <iostream>
#include <string>

using namespace std;

class Product{
    public:
        string product_name;
        int product_code;

        Product(string s, int p){
            this->product_name = s;
            this->product_code = p;
        }

};

string product_name;
int product_code;

int main() {
    cin >> product_name >> product_code;

    // Please write your code here.
    Product p = Product("codetree", 50);
    cout << "product " << p.product_code << " is " << p.product_name << endl;

    p.product_name = product_name;
    p.product_code = product_code;
    cout << "product " << p.product_code << " is " << p.product_name << endl;

    return 0;
}