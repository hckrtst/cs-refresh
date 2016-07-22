#include <iostream>
#include <string>

using namespace std;

string dec2bin(int n) {
    if (n > 1) {
        int rem = n % 2;
        return (dec2bin(n/2) + to_string(rem));
    } else if (n == 1){
        return "1";
    } else {
      return "0";
    }
}

int main() {
    cout << dec2bin(22) << endl;
    cout << dec2bin(0) << endl;
    return 0;
}
