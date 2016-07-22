#include <iostream>
#include <string>

using namespace std;

string dec2bin(int n) {
    if (n > 1) {
        int rem = n % 2;
        return (dec2bin(n/2) + to_string(rem));
    } else {
        return "1";
    }
}

int main() {
    cout << dec2bin(22) << endl;
    return 0;
} 
